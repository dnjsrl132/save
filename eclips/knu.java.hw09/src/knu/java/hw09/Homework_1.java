package knu.java.hw09;
class SharedCounter {
    int count = 0;
    synchronized public void increment() {
    	count++;
    }
    synchronized public void decrement() {
    	count--;
    }
}
class SuperCounter {
    SharedCounter counter;
    int times;
    public SuperCounter(SharedCounter counter, int times) {
    	this.counter=counter;
		this.times=times;
    }
}
class Increment extends SuperCounter implements Runnable {
	public Increment(SharedCounter counter,int times) {
		super(counter,times);
	}
    @Override
    public void run() {
    	for(;times>0;times--) {
    		counter.increment();
    	}
    }
}
class Decrement extends SuperCounter implements Runnable {
	public Decrement(SharedCounter counter,int times) {
		super(counter,times);
	}
	@Override
    public void run() {
		for(;times>0;times--) {
    		counter.decrement();
    	}
    }
}
public class Homework_1 {
    public static void main(String[] args) throws Exception {
        int inc = 2000;
        int dec = 1500;
        SharedCounter counter = new SharedCounter();
        Thread t1 = new Thread(new Increment(counter, inc));
        t1.start();
        Thread t2 = new Thread(new Decrement(counter, dec));
        t2.start();
        t1.join();
        t2.join();
        System.out.println(inc - dec);
        System.out.println(counter.count);
        System.out.println(counter.count == (inc - dec));
    }
}