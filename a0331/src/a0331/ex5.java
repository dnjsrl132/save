package a0331;
import java.util.Scanner;
public class ex5 {
	public static int Checkfirst(int seat) {
		if(seat>4) return 0;
		System.out.println("class : first\t seatnumber : "+(seat+1));
		return 1;
	}
	public static int Checkeconomy(int seat) {
		if(seat>4) return 0;
		System.out.println("class : economy\t seatnumber : "+(seat+6));
		return 1;
	}
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		boolean[] firstclass=new boolean[5];
		boolean[] economy=new boolean[5];
		int check,fseat=0,eseat=0;
		while(true) {
			if(fseat>4&&eseat>4) break;
			System.out.println("Please type 1 for First Class and Please type 2 for Economy.");
			check=s.nextInt();
			if(check==1) {
				if(Checkfirst(fseat++)==0) {
					System.out.println("if it¡¯s acceptable to be placed in the economy-class section(yes:1,no:0)");
					check=s.nextInt();
					if(check==0) break;
					Checkeconomy(eseat++);
				}
			}
			else {
				if(Checkeconomy(eseat++)==0) {
					System.out.println("if it¡¯s acceptable to be placed in the first-class section(yes:1,no:0)");
					check=s.nextInt();
					if(check==0) break;
					Checkfirst(fseat++);
				}
			}
		}
		System.out.println("Next flight leaves in 3 hours.");
	}
}
