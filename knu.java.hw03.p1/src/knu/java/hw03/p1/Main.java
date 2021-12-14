package knu.java.hw03.p1;
class Person{
	static String s_name;
	static String p_name;
	static boolean bad,p_bad;
	public Person(String name,boolean bad) {
		Person.s_name=name;
		Person.bad=bad;
	}
	public Person(String name) {
		Person.p_name=name;
	}
}
class Homework {
	static String name;
	static String professor_name;
	static int grade;
	static int type;//0=E,1=R,2=P
	static boolean done=false;
	public Homework(String name) {
		this.professor_name=name;
		this.type=0;
	}
	public Homework(String name,String Professor_name,int n) {
		this.name=name;
		this.professor_name=Professor_name;
		this.type=n;
	}
	public static void demo(int type) {
		if(type==2) System.out.print("\t demo");
	}
}
class Professor extends Person{
	public Professor(String name,boolean bad) {
		super(name);
		Person.p_bad=bad;
	}
	public static void assign(Homework h,String name,int n) {
		Homework ex;
		if(n==0) {
			ex=new Homework(Professor.p_name);
		}
		else {
			ex=new Homework(name,Professor.p_name,n);
		}
		h=ex;
	}
	public static void setGrade(Student s,int n) {
			s.exx[n].grade=(int)(Math.random()*11);
	}
}
class Student extends Person{
	static Homework[] exx=new Homework[3];
	static int[] cantpercent=new int[3];
	public Student(String name,boolean bad) {
		super(name,bad);
	}
	public static void setpercent(boolean bad) {
		if(bad) {
			int x=(int)(Math.random()*3);
			for(int i=0;i<3;i++) cantpercent[i]=10;
			cantpercent[x]=5;
		}
		else {
			cantpercent[0]=1;
			cantpercent[1]=2;
			cantpercent[2]=3;
		}
	}
	public static void submit(Homework h) {
		if((int)(Math.random()*10)>cantpercent[h.type]-1) {
			exx[h.type]=h;
			exx[h.type].done=true;
			h.demo(h.type);
		}
		else {
			exx[h.type]=null;
			exx[h.type].done=false;
			if(h.type==2) System.out.print("\t");
		}
	}
	public static void getGrade(Homework h) {
		System.out.print("\t"+h.professor_name+" ");
		if(h.done) {
			if(h.grade>5) System.out.print(h.grade+" È¯È£ ");
			else System.out.print(h.grade+" ÁÂÀý ");
		}
		else {
			System.out.print(h.done);
		}
	}
}

public class Main {
	public static void main(String[] args) {
		Professor[] p=new Professor[3];
		Student[] s=new Student[20];
		Homework[] h=new Homework[3];
		String[] p_name=new String[3];
		boolean bad=false;
		p_name[0]="exercise";
		p_name[1]="report";
		p_name[2]="project";
		for(int i=0;i<20;i++) {
			if(i==10) bad=true;
			s[i]=new Student("student"+(i+1),bad);
			s[i].setpercent(bad);
			System.out.print(s[i].s_name+"\t");
			for(int j=0;j<3;j++) {
				p[j]=new Professor(p_name[j],(j==2));
				p[j].assign(h[j], p_name[j]+"Homework", j);
				s[i].submit(h[j]);
				p[j].setGrade(s[i],j);
				s[i].getGrade(s[i].exx[j]);
			}
			System.out.println();
		}
	}
}

