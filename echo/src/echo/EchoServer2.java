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
        System.out.println("새로운 연결이 생성되었습니다...");
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
        System.out.println("새로운 연결이 종료되었습니다...");
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
            System.out.println("서버 소켓이 연결 대기중...");
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