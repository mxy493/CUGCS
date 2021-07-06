// file name��UDPClient.java
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
            System.out.println("���ܴ����ݱ�Socket�������ݱ�Socket�޷���ָ���˿�����!");
          } catch (IOException ioe) {
            System.out.println("����ͨ�ų��ִ���������" + ioe.toString());
        }
    }
}
