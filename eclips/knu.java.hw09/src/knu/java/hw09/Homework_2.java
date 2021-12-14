package knu.java.hw09;

class BankAccount {
    int money = 0;
    boolean transfer = true;
    synchronized public void deposit(int amount) throws InterruptedException {
    	while(!transfer) {
    		wait();
    	}
    	transfer=false;
    	{
    		money +=amount;
    		System.out.print("¿ëµ· "+amount + "¿ø ³Ö¾ú´Ù.");
    		System.out.println("ÀÜ°í: "+money);
    	}
    	notifyAll();
    }
    
    synchronized public void withdraw(int amount) throws InterruptedException {
    	while(transfer) {
    		wait();
    	}
    	transfer=true;
    	{
    		money-=amount;
    		System.out.print("¿ëµ· "+amount+"¿ø ›§¾î¿ä.");
    		System.out.println("ÀÜ°í : "+money);
    	}
    	notifyAll();
    }
}

class FamilyMember {
    BankAccount bankAccount;
    int amount;
    public FamilyMember(BankAccount bankAccount, int amount) {
    	this.bankAccount=bankAccount;
    	this.amount=amount;
    }
}

class Producer extends FamilyMember implements Runnable {
	public Producer(BankAccount bankAccount, int amount) {
		super(bankAccount,amount);
	}
    @Override
    public void run() {
    	try {
    		while(true) {
    			Thread.sleep((long)(Math.random()*1000));
    			bankAccount.deposit(amount);
    		}
    	}
    	catch(InterruptedException ie) {}
    }
    
}

class Consumer extends FamilyMember implements Runnable {
	public Consumer(BankAccount bankAccount, int amount) {
		super(bankAccount,amount);
	}
    @Override
    public void run() {
    	try {
    		while(true) {
    			Thread.sleep((long)(Math.random()*1000));
    			bankAccount.withdraw(amount);
    		}
    	}
    	catch(InterruptedException ie) {}
    }
}

public class Homework_2 {
    
    public static void main(String[] args) throws Exception {
        
        BankAccount bankAccount = new BankAccount();
        Producer father = new Producer(bankAccount, 10000);
        Producer mother = new Producer(bankAccount, 5000);
        Producer grandParent = new Producer(bankAccount, 50000);
        Consumer eldest = new Consumer(bankAccount, 30000);
        Consumer younger = new Consumer(bankAccount, 20000);
        Consumer youngest = new Consumer(bankAccount, 10000);
        
        Thread t1 = new Thread(father);
        Thread t2 = new Thread(mother);
        Thread t3 = new Thread(grandParent);
        Thread t4 = new Thread(eldest);
        Thread t5 = new Thread(younger);
        Thread t6 = new Thread(youngest);
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
        t6.start();
    }
}
