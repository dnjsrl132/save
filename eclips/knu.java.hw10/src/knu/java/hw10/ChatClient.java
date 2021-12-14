package knu.java.hw10;

import java.io.*;
import java.net.*;
import java.util.*;


class ChatClientHandler implements Runnable {

    Socket socket;
    BufferedReader in;
    PrintStream out;
    
    public ChatClientHandler(Socket socket) {
        this.socket = socket;
    }
    
    @Override
    public void run() {
        try {
        	in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String input = in.readLine();
            //if(input.isEmpty())
            System.out.println("받은 메시지 > " +input);
            socket.close();
           // TODO: 서버로부터 받은 메시지 처리
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
}

public class ChatClient {
    
    String host;
    int port;
    Scanner scanner;
    Socket socket;
    BufferedReader in;
    PrintStream out;
    
    public ChatClient(String host, int port) {
    	this.host=host;
    	this.port=port;
    	this.scanner=new Scanner(System.in);
    }
    
    public void start() throws IOException {
        socket = new Socket("localhost", port);
        System.out.println("서버와의 연결이 생성되었습니다...");
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintStream(socket.getOutputStream());
        Thread thread = new Thread(new ChatClientHandler(socket));
        // TODO: 클라이언트 핸들러 쓰레드 처리
        while (true) {
            System.out.print("보낼 메시지 > ");
            String message = scanner.nextLine();
            
            out.println(message);
            out.flush();
            
            String input = in.readLine();
            System.out.println("받은 메시지 > " +input);
            //thread.run();
            //thread.wait();
            //thread.notifyAll();
            // TODO: 서버로 메시지 전송
            
            if ("bye".equalsIgnoreCase(message))
                break;
        }
        socket.close();
        System.out.println("서버와의 연결이 종료되었습니다...");
    }

    public static void main(String[] args) {
        String host = "localhost";
        int port = 9191;
        ChatClient chatClient = new ChatClient(host, port);
        try {
            chatClient.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}