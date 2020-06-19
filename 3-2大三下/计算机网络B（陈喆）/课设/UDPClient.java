// file name：UDPClient.java
import java.net.*;
import java.io.*;
public class UDPClient {
    public static void main(String args[]) {
        try {
            DatagramSocket sendSocket = new DatagramSocket(3555);
            String string = "This is an Example for C/S Communication by UDP!";
            byte[] databyte = new byte[1000];
            databyte = string.getBytes();
DatagramPacket sendPacket=new DatagramPacket(databyte,string.length(),InetAddress.getByName("192.168.1.101"),5000);
            sendSocket.send(sendPacket);
            System.out.println("send the data: "+string);
            sendSocket.close();
          } catch (SocketException e) {
            System.out.println("不能打开数据报Socket，或数据报Socket无法与指定端口连接!");
          } catch (IOException ioe) {
            System.out.println("网络通信出现错误，问题在" + ioe.toString());
        }
    }
}
