package ex1;
interface Shape {
	public void draw();
}
class Circle implements Shape {
	double a;
	double b;
	public void draw() {
		System.out.println("I'm a Circle");
	}
}
class Rect implements Shape {
	public void draw() {
		System.out.println("I'm a Rect");
	}
}
class Square extends Rect {
	public void draw() {
		super.draw();
		System.out.println("I'm a Square");
	}
}
public class ex1 {
	public static void main(String[] args) {
		Circle a=new Circle();
	}
}

