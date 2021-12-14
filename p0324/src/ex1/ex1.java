package ex1;

public class ex1 {
	public static int a() {
		int sum=0;
		for(int i=1;i<=99;i+=2) {
			sum+=i;
		}
		return sum;
	}
	public static double b() {
		double sum=Math.pow(2.5, 3);
		return sum;
	}
	public static void c() {
		int i=1;
		while(i<=20) {
			System.out.print(i);
			if(i%5==0) System.out.println();
			else System.out.print("\t");
			i++;
		}
	}
	public static void d() {
		for(int i=1;i<=20;i++) {
			System.out.print(i);
			if(i%5==0) System.out.println();
			else System.out.print("\t");
		}
	}
	public static void main(String[] args) {
		System.out.println(a());
		System.out.println(b());
		c();
		d();
	}
}
