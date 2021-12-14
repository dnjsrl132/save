package a0331;
import java.util.Scanner;
public class ex4 {
	public static int dice() {
		int n;
		n=(int)(Math.random()*6);
		return n;
	}
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int a,b;
		int[] array=new int[11];
		for(int i=0;i<36000000;i++) {
			a=dice();
			b=dice();
			array[a+b]++;
		}
		for(int i=0;i<11;i++) {
			System.out.println((i+2)+"\t"+array[i]);
		}
	}

}
