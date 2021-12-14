package ±èµ¿À±0510;

public class Basic2Math {
	   private double a;
	   private double b;
	   public Basic2Math(double a, double b) {
	      this.a = a;
	      this.b = b;
	   }
	   
	   public void setA(double a){
	      this.a = a;
	   }
	   
	   public void setB(double b) {
	      this.b = b;
	   }
	   
	   public double sum(){
	      return BasicMath.sum(a, b);
	   }
	   
	   public double sub(){
	      return BasicMath.sub(a, b);
	   }
	   public double mul() {
		   return new BasicMath().mul(a,b);
	   }
	}
