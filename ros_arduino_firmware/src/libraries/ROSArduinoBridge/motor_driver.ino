/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
#include "commands.h";

//#include <Servo.h>
//Servo sabertoothRightChannel;
//Servo sabertoothLeftChannel;
void initMotorController() {
Serial2.begin(9600);
Serial2.write(0);//tell the sabertooth to stop both motors. 
}
boolean directionLeft = false;
boolean directionRight = false;
boolean direction(int i){//return the direction of rotation of a wheel
   if(i == LEFT){
      return directionLeft;
   }else{
      return directionRight;
   }

}
void setMotorSpeed(int i, int spd) {//send a command to the sabertooth to set a motor speed
if (i == LEFT){
  
if(spd < MIDSABERTOOTH){
directionLeft == BACKWARDS;
}else{
directionLeft == FORWARDS;
}

if(abs(spd-MIDSABERTOOTH) < 8){
  Serial2.write(64);
}else{
Serial2.write(map(spd, -255, 255, 1, 127));
Serial.println("The value has passed");
Serial.println(map(spd, -255, 255, 1, 127));
}

//Serial.println(spd);

//sabertoothLeftChannel.write(constrain(map(spd, -255, 255, 0, 180), MINSABERTOOTH, MAXSABERTOOTH));
}else{
  
if(spd < MIDSABERTOOTH){
directionRight == BACKWARDS;
}else{
directionRight == FORWARDS;
}
Serial2.write(map(spd, -255, 255, 128, 255));
//sabertoothRightChannel.write(constrain(map(spd, -255, 255, 0, 180), MINSABERTOOTH, MAXSABERTOOTH));
}
}
// A convenience function for setting both motor speeds
void setMotorSpeeds(int leftSpeed, int rightSpeed) {
setMotorSpeed(LEFT, leftSpeed);
setMotorSpeed(RIGHT, rightSpeed);
}



#endif
