public class InterpretDomain extends Thread {
    public String send() {
        return null;
    }

    public String receive() {
        return null;
    }

    private static int t_no = 0;

    public void run() {

    }

    public void runTest() {
        int my_no = t_no++;
        for (; ; ) {
            System.out.println("Thread " + my_no);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Interrupted");
            }
        }
    }

    public static void threadTest() {
        for (int i = 0; i < 10; i++) {
            Thread t = new Thread(new InterpretDomain());
            t.start();
        }
    }

    public static void main(String[] args) {
        Thread send = new Thread(new UDPSend());
        Thread receive = new Thread(new UDPReceive());

        send.start();
        receive.start();
    }
}
