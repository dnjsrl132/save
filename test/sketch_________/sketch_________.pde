void setup(){
  size(200,200);
  frameRate(30);
}
void draw(){
  background(200);
  f();
}
void f(){
  fill(0,0,255);
  ellipse(mouseX,mouseY,80,60);
  arc(mouseX,mouseY,60,30,0,PI);
  fill(255,0,0);
  ellipse(mouseX-20,mouseY-30,32,32);
  ellipse(mouseX+20,mouseY-30,32,32);
  fill(0);
  ellipse(mouseX-20,mouseY-30,5,5);
  ellipse(mouseX+20,mouseY-30,5,5);
}
