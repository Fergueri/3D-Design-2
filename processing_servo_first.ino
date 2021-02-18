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
     delay(1000);
     servo.write(180);
     delay(1000);
   } else {
     servo.write(30);
     delay(1000);
     
   }
   
}
