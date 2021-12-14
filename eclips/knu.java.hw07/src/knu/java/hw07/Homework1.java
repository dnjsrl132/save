package knu.java.hw07;

import java.util.*;

interface Grade{
	public static final int A=0;
	public static final int B=1;
	public static final int C=2;
	public static final int D=3;
	public static final int F=4;
}

class GradeComparator implements Comparator<Student>{
	public int compare(Student s1,Student s2) {
		return s1.getGrade()-s2.getGrade();
	}
}
class Student implements Comparable<Student>{
	private int id;
	private String name;
	private int grade;
	
	public Student(int id, String name, int grade) {
		this.id=id;
		this.name=name;
		this.grade=grade;
	}
	public String toString() {
		char s;
		switch(grade) {
		case 0: s='A'; break;
		case 1: s='B'; break;
		case 2: s='C'; break;
		case 3: s='D'; break;
		case 4: s='F'; break;
		default : s='F';break;
		}
		return "("+id+","+name+","+s+")";
	}
	public int compareTo(Student student) {
		return this.name.compareTo(student.getName());
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id=id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name=name;
	}
	public int getGrade() {
		return grade;
	}
	public void setGrade(int grade) {
		this.grade=grade;
	}
}

public class Homework1 {
	public static void main(String[] args) {
		String[] names= {"홍길동","대도서관","뽀로로와친구들","펭수","스티브잡스"};
		int[] grades= {Grade.A,Grade.C,Grade.F,Grade.D,Grade.B};
		Student s;
		
		List<Student> students = new ArrayList<Student>();
		for(int i=0;i<names.length;i++) {
			students.add(new Student(i+1,names[i],grades[i]));
		}
		System.out.println(students);
		Collections.sort(students);
		System.out.println(students);
		Collections.sort(students,new GradeComparator());
		System.out.println(students);
		Collections.sort(students,new Comparator<Student>(){
			public int compare(Student s1,Student s2) {
				return s1.getName().length()-s2.getName().length();
			}
		});
		System.out.println(students);
	}
}
