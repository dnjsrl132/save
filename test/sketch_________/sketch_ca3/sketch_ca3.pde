  size(200,200);
  noFill();
  triangle(45,20,35,35,55,35);
  fill(255);
  rect(40,0,10,20);
  translate(50,50);
  ellipse(39, 15, 38, 30); // head
  rect(14, 32, 50, 50); // body
  pushMatrix();//left arm
  translate(12, 32);
  rotate(radians(150));
  rect(-12, 0, 12, 50);
  popMatrix();
  pushMatrix();//right arm
  translate(66, 32);
  rotate(radians(-20));
  rect(0, 0, 12, 50); 
  popMatrix();
  rect(22, 84, 16, 50);//left foot 
  rect(40, 84, 16, 50); //right foot
  pushMatrix();//bag
  translate(70,80);
  rect(0,0,40,30);
  rect(3,10,15,15);
  rect(23,10,15,15);
  popMatrix();
  ellipse(30, 12, 12, 12); //eyes
  ellipse(47, 12, 12, 12);
