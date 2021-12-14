
void setup(){
  size(800,400);
  frameRate(30);
}
void draw(){
  f();
}
void f(){
  triangle(100,50,50,100,150,100);
  rect(50,100,100,100);
  rect(100,150,40,50);
  translate(150,0);
}
