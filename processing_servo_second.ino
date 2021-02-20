 #include <Servo.h> 
 
 char val; // Data received from the serial port
 int servoPin = 13; //servo pin
Servo servo;
 
 void setup() {
   Serial.begin(9600); // Start serial communication at 9600 bps
 }
 void loop() {
int servoState = servo.read();
   if (Serial.available()) 
   { // If data is available to read,
     val = Serial.read(); // read it and store it in val
     
   }
   if (val == '1') 
   { // If 1 was received
     servo.attach(servoPin);
     delay(10);//delay to give time for motor
     servo.write(360);
     delay(10);//delay to give time for motor i noticed that this needed a very small delay to actually work
   } else { //otherwise
     servo.write(0);
     delay(10);//delay to give time for motor
     
   }
   
}
