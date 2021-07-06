// file name：ComputeTCPServer.java
import java.net.*;
import java.io.*;
public class ComputeTCPServer{
        public static void main(String srgs[]) {
        ServerSocket sc = null;
        Socket socket=null;
            try {
           sc= new ServerSocket(4421);//创建服务器套接字
            System.out.println("端口号:" + sc.getLocalPort());
            System.out.println("服务器已经启动...");
               socket = sc.accept();   //等待客户端连接
                System.out.println("已经建立连接");
                //获得网络输入流对象的引用
                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                ////获得网络输出流对象的引用
          PrintWriter out=new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
          String   aline=in.readLine();//读取客户端传送来的数据
          System.out.println("从客户端接收到信息为："+aline); //通过网络输出流返回结果给客户端
          out.println(aline);
          out.close();
          in.close();
          sc.close();
               } catch (Exception e) {
            System.out.println(e);
        }
    }
}
