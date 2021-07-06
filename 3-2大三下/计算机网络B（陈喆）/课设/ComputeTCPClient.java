// file name：ComputeTCPClient.java
import java.net.*;
import java.io.*;
public class ComputeTCPClient {
    public static void main(String srgs[]) {
      try {
           //创建连接特定服务器的指定端口的Socket对象
        Socket socket = new Socket("192.168.1.101", 4421);
            //获得从服务器端来的网络输入流
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            //获得从客户端向服务器端输出数据的网络输出流
            PrintWriter out=new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
            //创建键盘输入流，以便客户端从键盘上输入信息
            BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("请输入待发送的数据：");  
            String str=stdin.readLine(); //从键盘读入待发送的数据
            out.println(str);  //通过网络传送到服务器
            str=in.readLine();//从网络输入流读取结果
            System.out.println( "从服务器接收到的结果为："+str); //输出服务器返回的结果
       }
        catch (Exception e) {
            System.out.println(e);
        }
     }
}
