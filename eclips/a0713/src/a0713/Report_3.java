package a0713;
import java.util.Scanner;
public class Report_3 {
   static class Phone {
       private String name;
       private String tel;
       public Phone(String name, String tel) { //������
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
            System.out.print("�ο���>>");
            Scanner scan = new Scanner(System.in);
            num = scan.nextInt();
            p = new Phone[num];
            for(int i = 0; i<num; i++) {
                System.out.print("�̸��� ��ȭ��ȣ(��ȣ�� ���������� �Է�)>>");
                String name = scan.next();
                String tel = scan.next();
                p[i] =  new Phone(name, tel);
            }
            System.out.println("����Ǿ����ϴ�...");
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
            System.out.println("�˻��� �̸�>>");
            String name = scan.next(); //�˻��̸�
            if(name.equals("exit")) {
               System.out.println("���α׷��� �����մϴ�...");
               break;
            }
            else {
               String tel = search(name);
               if(tel.equals("\0")) tel="none";
               System.out.println(name+"�� ��ȣ��"+tel+"�Դϴ�.");
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