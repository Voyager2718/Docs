import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPReceive extends Thread {
    private byte[] buffer = new byte[65508];
    private static final int port = 80;

    public void getUDPMessage() {
        try {
            DatagramSocket serverSocket = new DatagramSocket(port);
            byte[] receiveData = new byte[1024];
            while (true) {
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                serverSocket.receive(receivePacket);
                String sentence = new String(receivePacket.getData());
                System.out.println("RECEIVED: " + sentence);
            }
        } catch (Exception e) {
            System.out.println("Unable to establish socket.");
        }
    }

    public void run() {
        UDPReceive udpReceive = new UDPReceive();
        udpReceive.getUDPMessage();
    }
}
