import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPSend extends Thread {
    private static final String hostAddress = "8.8.8.8";
    private static final int port = 53;

    public void sendUDPMessage(byte[] message) {
        try {
            InetAddress inetAddress = InetAddress.getByName(hostAddress);
            DatagramSocket socket = new DatagramSocket(port);

            DatagramPacket sendPacket = new DatagramPacket(message, message.length, inetAddress, port);
            socket.send(sendPacket);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String args[]) {
        UDPSend udpSend = new UDPSend();
        byte[] message = {(byte) 0x08bb, (byte) 0x0100,
                (byte) 0x0001, (byte) 0x0000,
                (byte) 0x0000, (byte) 0x0000,
                (byte) 0x0377, (byte) 0x7777,
                (byte) 0x046c, (byte) 0x6966,
                (byte) 0x6c02, (byte) 0x6672,
                (byte) 0x00, (byte) 0x01,
                (byte) 0x00, (byte) 0x01};
        udpSend.sendUDPMessage(message);
    }

    public void run() {
        UDPSend udpSend = new UDPSend();
        byte[] message = {(byte) 0x08bb, (byte) 0x0100,
                (byte) 0x0001, (byte) 0x0000,
                (byte) 0x0000, (byte) 0x0000,
                (byte) 0x0377, (byte) 0x7777,
                (byte) 0x046c, (byte) 0x6966,
                (byte) 0x6c02, (byte) 0x6672,
                (byte) 0x00, (byte) 0x01,
                (byte) 0x00, (byte) 0x01};
        udpSend.sendUDPMessage(message);
    }
}
