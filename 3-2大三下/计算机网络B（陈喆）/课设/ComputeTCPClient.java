// file name��ComputeTCPClient.java
import java.net.*;
import java.io.*;
public class ComputeTCPClient {
    public static void main(String srgs[]) {
      try {
           //���������ض���������ָ���˿ڵ�Socket����
        Socket socket = new Socket("192.168.1.101", 4421);
            //��ôӷ���������������������
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            //��ôӿͻ������������������ݵ����������
            PrintWriter out=new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
            //�����������������Ա�ͻ��˴Ӽ�����������Ϣ
            BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("����������͵����ݣ�");  
            String str=stdin.readLine(); //�Ӽ��̶�������͵�����
            out.println(str);  //ͨ�����紫�͵�������
            str=in.readLine();//��������������ȡ���
            System.out.println( "�ӷ��������յ��Ľ��Ϊ��"+str); //������������صĽ��
       }
        catch (Exception e) {
            System.out.println(e);
        }
     }
}
