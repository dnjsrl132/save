package knu.java.hw05;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		GameObject bear=new GameObject(1,1,"bear");
		GameObject fish=new GameObject(bear.ROW/2,bear.COL/2,"fish");
		
		Scanner s=new Scanner(System.in);
		String c;
		
		int NEWS=0;
		while(bear.collide(fish)!=true) {
			for(int i=0;i<bear.ROW;i++) {
				for(int j=0;j<bear.COL;j++) {
					if(bear.getX()==i&&bear.getY()==j) System.out.print(bear.getShape());
					else if(fish.getX()==i&&fish.getY()==j) System.out.print(fish.getShape());
					else System.out.print('.');
				}
				System.out.println();
			}
			System.out.println("왼쪽(a),아래(s),위(d),오른쪽(f)>>");
			c=s.next();
			switch(c) {
			case "a": NEWS=1;break;
			case "s": NEWS=2;break;
			case "d": NEWS=0;break;
			case "f": NEWS=3;break;
			}
			bear.move(NEWS);
			if(Math.random()*5<2) fish.move((int)(Math.random()*4)); 
		}
		for(int i=0;i<bear.ROW;i++) {
			for(int j=0;j<bear.COL;j++) {
				if(bear.getX()==i&&bear.getY()==j) System.out.print(bear.getShape());
				else if(fish.getX()==i&&fish.getY()==j) System.out.print(fish.getShape());
				else System.out.print('.');
			}
			System.out.println();
		}
		System.out.println("bear eat fish");
	}
}
