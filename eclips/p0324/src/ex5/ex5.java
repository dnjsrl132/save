package ex5;

public class ex5 {
	public static boolean primeNumber(int n) {
		int i=2;
		boolean prime=true; 
		while(i*i<=n) {
			if(n%i==0) {
				prime=false;
				break;
			}
			i++;
		}
		return prime;
	}
	public static void main(String[] args) {
		int n=1000;
		for(int i=2;i<n;i++) {
			if(primeNumber(i)) System.out.println(i);
		}
	}
}
