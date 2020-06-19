// file name：UDPServer.java
import java.net.*;
import java.io.*;
public class UDPServer {
    static public void main(String args[]) {
        try {
            DatagramSocket receiveSocket = new DatagramSocket(5000);
            byte buf[] = new byte[1000]; //定义接收缓冲 
            DatagramPacket receivePacket = new DatagramPacket(buf, buf.length);
            System.out.println("Startinig to receive packet…");
            while (true) {
                receiveSocket.receive(receivePacket); //监听数据
                String name = receivePacket.getAddress().toString();
                System.out.println("\n来自主机：" + name + "\n端口：" + receivePacket.getPort());
                String s = new String(receivePacket.getData(), 0, receivePacket.getLength());
//将接收的数据存入字符串s
                System.out.println("The received data: " + s);
                receiveSocket.close();
            }
        } catch (SocketException e) {
            e.printStackTrace();
            System.exit(1);
        } catch (IOException e) {
            System.out.println("网络通信出现错误，问题在" + e.toString());
        }
    }
}
