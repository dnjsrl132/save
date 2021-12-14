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
        System.out.println("���ο� ������ �����Ǿ����ϴ�...");
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
            // TODO: Ŭ���̾�Ʈ�κ��� ���� �޽����� ��� �������� ���Ͽ� ����
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("���ο� ������ ����Ǿ����ϴ�...");
    }

    /**
     * run()�޼ҵ忡�� �޽��� ���۽ÿ� �� �޼ҵ带 �ݵ�� �̿��� ��: 
     * �ϳ��� �����尡 Ŭ���̾�Ʈ�� �޽��� ������
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
        // TODO: �ʱ�ȭ
    }
    
    public void start() throws IOException {
        serverSocket = new ServerSocket(port);
        while (true) {
            System.out.println("���� ������ ���� �����...");
            Socket socket = serverSocket.accept();
            
            Thread thread=new Thread(new ChatServerHandler(socket,clientList));
            thread.start();
            // TODO: Ŭ���̾�Ʈ ��� ������ ó�� (�������� ArrayList ����)
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