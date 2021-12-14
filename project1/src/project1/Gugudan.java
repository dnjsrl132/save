package project1;

public class Gugudan {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i,j;
		System.out.println(Math.random()*10);
		for(i=2;i<10;i++) {
			for(j=1;j<10;j++) {
				System.out.print(i+"*"+j+"="+(i*j)+"\t");
			}
			System.out.println("\n");
		}
	}
}
