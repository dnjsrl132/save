package a0331;
import java.util.Scanner;

public class ex1 {
	public static void main(String[] args) {
		int[] array;
		//a)
		System.out.println("a)");
		array=new int[10];
		for(int i=0;i<10;i++) {
			System.out.print(array[i]+"\t");
		}
		
		//b)
		array=new int[15];
		Scanner scanner=new Scanner(System.in);
		System.out.println("\nput number * 15");
		for(int i=0;i<15;i++) {
			array[i]=scanner.nextInt();
		}
		System.out.println("b)");
		for(int i=0;i<15;i++) {
			System.out.print(array[i]+"\t");
		}
		
		//c)
		System.out.println("\nc)");
		int[] max;
		max=new int[5];
		for(int i=0;i<15;i++) {
			int temp=array[i];
			for(int j=0;j<5;j++) {
				if(temp>max[j]) {
					temp+=max[j];
					max[j]=temp-max[j];
					temp-=max[j];
				}
			}
		}
		for(int i=0;i<5;i++) {
			System.out.print(max[i]+"\t");
		}
	}
}
