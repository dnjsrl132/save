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
            System.out.println("���� �޽��� > " +input);
            socket.close();
           // TODO: �����κ��� ���� �޽��� ó��
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
        System.out.println("�������� ������ �����Ǿ����ϴ�...");
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintStream(socket.getOutputStream());
        Thread thread = new Thread(new ChatClientHandler(socket));
        // TODO: Ŭ���̾�Ʈ �ڵ鷯 ������ ó��
        while (true) {
            System.out.print("���� �޽��� > ");
            String message = scanner.nextLine();
            
            out.println(message);
            out.flush();
            
            String input = in.readLine();
            System.out.println("���� �޽��� > " +input);
            //thread.run();
            //thread.wait();
            //thread.notifyAll();
            // TODO: ������ �޽��� ����
            
            if ("bye".equalsIgnoreCase(message))
                break;
        }
        socket.close();
        System.out.println("�������� ������ ����Ǿ����ϴ�...");
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