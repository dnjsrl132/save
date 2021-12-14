package knu.java.hw08;

import java.util.Scanner;

class HomeworkThread2 implements Runnable {

    private int count;
    private int sleep;

    public HomeworkThread2(int count, int sleep) {
    	this.count=count;
    	this.sleep=sleep;
    }
    
    @Override
    public void run() {
        Thread thread = Thread.currentThread();
        while(count>0) {
        	System.out.println("Thread Id = "+thread.getId()+": count "+count);
        	count--;
        	try {
        		Thread.sleep(sleep*1000);
        	}
        	catch(InterruptedException e) {
        		System.err.println("Thread Id= "+thread.getId()+": I'm interrupted!");
        		return;
        	}
        }
        System.out.println("Thread Id = "+thread.getId()+": finish");
    }
}

public class Homework2 {
	public static void main(String[] args) {
        Thread[] threads = new Thread[3];
        for (int i = 0; i < threads.length; i++) {
            threads[i] = new Thread(new HomeworkThread2(10, 1)); // 10부터 카운트 다운 (1초씩)
            threads[i].start();
        }
        
        Scanner scanner = new Scanner(System.in);
        try {
            while (true) {
                int num = scanner.nextInt();
                threads[num].interrupt();
            }
        } finally {
            scanner.close();
        }
    }
}
