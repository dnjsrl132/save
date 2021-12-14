package knu.java.hw10;

import java.io.*;
import java.net.*;
import java.util.*;

class ChatServerHandler implements Runnable {

    Socket socket;
    BufferedReader in;
    PrintStream out;
    ArrayList<ChatServerHandler> clientList;
    int i;

    public ChatServerHandler(Socket socket, ArrayList<ChatServerHandler> clientList) {
        this.socket = socket;
        this.clientList=clientList;
        
    }

    @Override
    public void run() {
        long id = Thread.currentThread().getId();
        System.out.println("새로운 연결이 생성되었습니다...");
        try {
        	in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintStream(socket.getOutputStream());
            while (true) {
                String input = in.readLine();
                System.out.println("id="+id+":"+input);
                sendMessage(id,input);
                
                if ("Bye".equalsIgnoreCase(input))
                    break;
            }
            socket.close();
            // TODO: 클라이언트로부터 받은 메시지를 모든 쓰레드의 소켓에 쓰기
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("새로운 연결이 종료되었습니다...");
    }

    /**
     * run()메소드에서 메시지 전송시에 이 메소드를 반드시 이용할 것: 
     * 하나의 쓰레드가 클라이언트로 메시지 전송함
     */
    public void sendMessage(long id, String message) {
        System.out.println("Sending message.. " + message);
        out.println("[id=" + id + "]: " +message);
        out.flush();
    }
}

public class ChatServer {
    
    int port;
    ServerSocket serverSocket;
    ArrayList<ChatServerHandler> clientList;
    
    public ChatServer(int port) {
    	this.port=port;
        // TODO: 초기화
    }
    
    public void start() throws IOException {
        serverSocket = new ServerSocket(port);
        while (true) {
            System.out.println("서버 소켓이 연결 대기중...");
            Socket socket = serverSocket.accept();
            
            Thread thread=new Thread(new ChatServerHandler(socket,clientList));
            thread.start();
            // TODO: 클라이언트 통신 쓰레드 처리 (쓰레드의 ArrayList 관리)
        }
    }

    public static void main(String[] args) {
        int port = 9191;
        ChatServer chatServer = new ChatServer(port);
        try {
            chatServer.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
}