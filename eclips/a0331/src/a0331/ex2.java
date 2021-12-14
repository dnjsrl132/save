package a0331;
import java.util.Scanner;
public class ex2 {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int[] array=new int[5];
		int count=0;
		int temp;
		for(int i=0;i<5;i++) {
			System.out.println("\n"+(i+1)+"번째 원소");
			array[i]=s.nextInt();
			count=0;
			for(int j=0;j<i;j++) {
				if(array[i]==array[j]) {
					count++;
					break;
				}
			}
			if(count!=0) i--;
			else {
				for(int j=0;j<=i;j++) {
					System.out.print(array[j]+"\t");
				}
			}
		}
	}
}
