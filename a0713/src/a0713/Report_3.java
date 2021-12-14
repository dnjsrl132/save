package a0713;
import java.util.Scanner;
public class Report_3 {
   static class Phone {
       private String name;
       private String tel;
       public Phone(String name, String tel) { //생성자
           this.name = name;
           this.tel = tel;
       }
       public String getName() {
           return this.name;
       }
       public String getTel() {
           return this.tel;
       }
   }
   public static class PhoneManager {
      private Phone [] p;
      
      private void read() {
    	  	int num;
            System.out.print("인원수>>");
            Scanner scan = new Scanner(System.in);
            num = scan.nextInt();
            p = new Phone[num];
            for(int i = 0; i<num; i++) {
                System.out.print("이름과 전화번호(번호는 연속적으로 입력)>>");
                String name = scan.next();
                String tel = scan.next();
                p[i] =  new Phone(name, tel);
            }
            System.out.println("저장되었습니다...");
            //scan.close();
      }
      
      private String search (String name) {
            for(int i = 0; i<p.length; i++)
                if(name.equals(p[i].getName()))
                    return p[i].getTel();
            return "\0";
      }
      
      public void run() {
         Scanner scan = new Scanner(System.in);
         read();
         while(true) {
            System.out.println("검색할 이름>>");
            String name = scan.next(); //검색이름
            if(name.equals("exit")) {
               System.out.println("프로그램을 종료합니다...");
               break;
            }
            else {
               String tel = search(name);
               if(tel.equals("\0")) tel="none";
               System.out.println(name+"의 번호는"+tel+"입니다.");
            }
         }
         scan.close();
      }
   }
   public static void main(String[] args) {
        PhoneManager p = new PhoneManager();
        p.run();
   }
}