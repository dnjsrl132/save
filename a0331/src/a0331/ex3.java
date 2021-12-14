package a0331;
import java.util.Scanner;
public class ex3 {
	public static int fibo(int n) {
		int f=0,s=1,t=1;
		if(n==1) return f;
		if(n==2) return s;
		for(int i=0;i<n-2;i++) {
			t=f+s;
			f=s;
			s=t;
		}
		return t;
	}
	public static double fibo2(int n) {
		double f=0,s=0.000000001,t=0;
		for(int i=0;i<n-2;i++) {
			t=f+s;
			f=s;
			s=t;
		}
		return t;
	}
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		System.out.println(n+"\t"+fibo(n));
		while(fibo(n)>0) {
			n++;
		}
		System.out.println((n-1)+"\t"+fibo(n-1));
		while(fibo2(n)<9999999) {
			n++;
		}
		System.out.println((n-1)+"\t"+fibo2(n-1));
	}
}
