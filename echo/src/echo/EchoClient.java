package echo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

public class EchoClient {
    
    String host;
    int port;
    Scanner scanner;
    Socket socket;
    BufferedReader in;
    PrintStream out;
    
    public EchoClient(String host, int port) {
        this.host = host;
        this.port = port;
        this.scanner = new Scanner(System.in);
    }
    
    public void start() throws IOException {
        socket = new Socket("localhost", port);
        System.out.println("서버와의 연결이 생성되었습니다...");
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintStream(socket.getOutputStream());
        while (true) {
            System.out.print("보낼 메시지 > ");
            String message = scanner.nextLine();
            out.println(message);
            out.flush();
            String response = in.readLine();
            System.out.println("받은 메시지 > " + response);
            if ("Bye".equalsIgnoreCase(response))
                break;
        }
        socket.close();
        System.out.println("서버와의 연결이 종료되었습니다...");
    }

    public static void main(String[] args) {
        String host = "localhost";
        int port = 9191;
        EchoClient echoClient = new EchoClient(host, port);
        try {
            echoClient.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
}