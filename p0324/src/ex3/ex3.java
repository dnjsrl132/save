package ex3;

public class ex3 {
	public static int abs(int n) {
		if(n<0) n=-1*n;
		return n+1;
	}
	public static void main(String[] args) {
		int n=5;
		int k=0;
		for(int i=1;i<=n*2;i++) {
			for(int j=1;j<=n;j++) {
				if(j<abs(n-i)) System.out.print(" ");
				else System.out.print("*");
			}
			if(i>n) k=abs(2*n-i)-1;
			else k=i;
			for(int j=1;j<k;j++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
