// file name��ComputeTCPServer.java
import java.net.*;
import java.io.*;
public class ComputeTCPServer{
        public static void main(String srgs[]) {
        ServerSocket sc = null;
        Socket socket=null;
            try {
           sc= new ServerSocket(4421);//�����������׽���
            System.out.println("�˿ں�:" + sc.getLocalPort());
            System.out.println("�������Ѿ�����...");
               socket = sc.accept();   //�ȴ��ͻ�������
                System.out.println("�Ѿ���������");
                //����������������������
                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                ////���������������������
          PrintWriter out=new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
          String   aline=in.readLine();//��ȡ�ͻ��˴�����������
          System.out.println("�ӿͻ��˽��յ���ϢΪ��"+aline); //ͨ��������������ؽ�����ͻ���
          out.println(aline);
          out.close();
          in.close();
          sc.close();
               } catch (Exception e) {
            System.out.println(e);
        }
    }
}
