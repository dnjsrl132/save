package echo;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

class EchoHandler implements Runnable {

    Socket socket;
    BufferedReader in;
    PrintStream out;

    public EchoHandler(Socket socket) {
        this.socket = socket;
    }
    
    @Override
    public void run() {
        System.out.println("���ο� ������ �����Ǿ����ϴ�...");
        try {
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintStream(socket.getOutputStream());
            while (true) {
                String input = in.readLine();
                out.println(input);
                if ("Bye".equalsIgnoreCase(input))
                    break;
            }
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("���ο� ������ ����Ǿ����ϴ�...");
    }

}

public class EchoServer2 {
    
    int port;
    ServerSocket serverSocket;
    
    public EchoServer2(int port) {
        this.port = port;
    }
    
    public void start() throws IOException {
        serverSocket = new ServerSocket(port);
        while (true) {
            System.out.println("���� ������ ���� �����...");
            Socket socket = serverSocket.accept();
            Thread thread = new Thread(new EchoHandler(socket));
            thread.start();
        }
    }

    public static void main(String[] args) {
        int port = 9191;
        EchoServer2 echoServer = new EchoServer2(port);
        try {
            echoServer.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
}