import javax.naming.NamingException;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class DnsLookup {
    private static final String dns = "8.8.8.8";

    private void displayDetails(String hostname, InetAddress inetAddress) {
        System.out.println("Which Host:" + hostname);
        System.out.println("Canonical Host Name:" + inetAddress.getCanonicalHostName());
        System.out.println("Host Name:" + inetAddress.getHostName());
        System.out.println("Host Address:" + inetAddress.getHostAddress());
        System.out.println("--------------------------");
    }

    public void lookup(String hostname) {
        try {
            InetAddress inetAddress = InetAddress.getByName(hostname);
            displayDetails(hostname, inetAddress);
        } catch (UnknownHostException e) {
            System.out.println("Unknown host.");
        }
    }

    public static void main(String args[]) {
        DnsLookup dnsLookup = new DnsLookup();
        while (true) {
            System.out.println("Enter the domain:");
            Scanner scanner = new Scanner(System.in);
            String domain = scanner.nextLine();
            dnsLookup.lookup(domain);
        }
    }
}
