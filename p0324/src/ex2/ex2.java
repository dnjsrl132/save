package ex2;

public class ex2 {
	public static void a(int n) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=i;j++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
	public static void b(int n) {
		for(int i=1;i<=n;i++) {
			for(int j=10;j>=i;j--) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
	public static void c(int n) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(j<i) System.out.print(" ");
				else System.out.print("*");
			}
			System.out.println();
		}
	}
	public static void d(int n) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(j<n-i+1) System.out.print(" ");
				else System.out.print("*");
			}
			System.out.println();
		}
	}
	public static void main(String[] args) {
		int n=10;
		a(n);
		b(n);
		c(n);
		d(n);
	}
}
