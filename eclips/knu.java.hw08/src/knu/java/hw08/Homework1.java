package knu.java.hw08;

class HomeworkThread1 implements Runnable {
    
    private int count;
    private int sleep;
    
    public HomeworkThread1(int count, int sleep) {
        // TODO: 초기화 할 것.
    	this.count=count;
    	this.sleep=sleep;
    }
    
    @Override
    public void run() {
        // TODO: 오버라이딩 할 것.
    	for(;count>=0;count--) {
    		if(count>0)System.out.println("count : "+count);
    		else System.out.println("Fire");
    		try {
    			Thread.sleep(sleep*1000);
    		}
    		catch(InterruptedException e) {return;}
    	}
    }
    public int getcount() {
    	return count;
    }
}

public class Homework1 {
    
    public static void main(String[] args) throws InterruptedException {
        HomeworkThread1 hw1 = new HomeworkThread1(3, 1);
        Thread thread = new Thread(hw1);
        thread.start();
        thread.join();
        System.out.println("Good Job!");
    }
    
}