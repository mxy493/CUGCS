// file name��UDPServer.java
import java.net.*;
import java.io.*;
public class UDPServer {
    static public void main(String args[]) {
        try {
            DatagramSocket receiveSocket = new DatagramSocket(5000);
            byte buf[] = new byte[1000]; //������ջ��� 
            DatagramPacket receivePacket = new DatagramPacket(buf, buf.length);
            System.out.println("Startinig to receive packet��");
            while (true) {
                receiveSocket.receive(receivePacket); //��������
                String name = receivePacket.getAddress().toString();
                System.out.println("\n����������" + name + "\n�˿ڣ�" + receivePacket.getPort());
                String s = new String(receivePacket.getData(), 0, receivePacket.getLength());
//�����յ����ݴ����ַ���s
                System.out.println("The received data: " + s);
                receiveSocket.close();
            }
        } catch (SocketException e) {
            e.printStackTrace();
            System.exit(1);
        } catch (IOException e) {
            System.out.println("����ͨ�ų��ִ���������" + e.toString());
        }
    }
}
