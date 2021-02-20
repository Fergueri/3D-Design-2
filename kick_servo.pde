import processing.serial.*;

Serial myPort;  // Create object from Serial class
PImage img;
PImage img2;
void setup() 
{
  size(600,600); //make our canvas 600 x 600 pixels big
  String portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  img = loadImage("kick1.png");//img usually
  img = loadImage("kick2.png");//img when pressed
}
void draw() {
  image(img, 0,0);
  if (mousePressed == true) 
  {                           //if we clicked in the window
  image(img2, 0,0);
   myPort.write('1');         //send a 1
   println("10");   
  } else 
  {                           //otherwise
  myPort.write('0');          //send a 0
  }   
}
