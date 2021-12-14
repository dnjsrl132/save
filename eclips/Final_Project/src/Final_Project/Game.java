package Final_Project;

import java.util.Scanner;

class moving implements Runnable{
	GameObject bear;
	GameObject fish;
	
	public moving(GameObject bear,GameObject fish) {
		this.bear=bear;
		this.fish=fish;
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		try {
			while(bear.collide(fish)!=true) {
				Thread.sleep((long)(Math.random()*1000));
				bear.bearmove();
				fish.fishmove();
			}
		}
		catch(InterruptedException ie) {}
	}
}
class printing implements Runnable{
	public int money,count;
	GameObject bear;
	GameObject fish;
	
	public printing(int money,int count,GameObject bear,GameObject fish) {
		// TODO Auto-generated constructor stub
		this.money=money;
		this.count=count;
		this.bear=bear;
		this.fish=fish;
	}
	public void run() {
		try {
    		while(bear.collide(fish)!=true) {
    			Thread.sleep((long)(Math.random()*1000));
    			bear.waiting(bear,fish);
    		}
    		System.out.println("bear eat fish");
    		int x=this.bear.getCount();
    		if(x==count) x=2*count;
    		else if (x>count) x=2*count-x;
    		else x-=count;
    		money+=x;
    		System.out.println("움직인 횟수 : "+this.bear.getCount()+", 예측 횟수 : "+count+", 현재 점수 :"+x+", 총 점수 : "+money);
    	}
    	catch(InterruptedException ie) {}
	}
	public int getMoney() {
		return money;
	}
	public void set(int count) {
		this.count=count;
	}
}
public class Game {
	public static void main(String[] args) {
		GameObject bear=new GameObject(0,0,"bear");
		GameObject fish=new GameObject(bear.ROW/2,bear.COL/2,"fish");
		
		Scanner s=new Scanner(System.in);
		int count,money=100;
		
		System.out.println("곰은 얼마만에 물고기를 먹을까?");
		count=s.nextInt();
		printing P=new printing(money,count,bear,fish);
		
		while(true) {
			Thread t1=new Thread(new moving(bear,fish));
			Thread t2=new Thread(P);
		
			t1.start();
			t2.start();
			
			money=P.getMoney();
			
			count=s.nextInt();
			if(count==0) break;
			
			bear.set(0, 0);
			fish.set(bear.ROW/2,bear.COL/2);
			P.set(count);
		}
		money=P.getMoney();
		System.out.println("game over!\n당신의 최종 점수는 ? "+money);
	}
}
