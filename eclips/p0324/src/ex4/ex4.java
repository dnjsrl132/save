package ex4;

public class ex4 {
	public static void perfectNumber(int n) {
		int i=1,count=0,sum=0;
		int[] array=new int[n/2];
		while(i<=n/2) {
			if(n%i==0) {
				array[count]=i;
				count++;
				sum+=i;
			}
			i++;
		}
		if(sum==n) {
			for(i=0;i<count;i++)
				System.out.print(array[i]+" ");
			System.out.println("="+n);
		}
	}
	public static void main(String[] args) {
		int n=100000;
		for(int i=2;i<n;i++) {
			perfectNumber(i);
		}
	}
}
