/* *************************************************************
 Encoder definitions
 
 Add a "#if defined" block to this file to include support for
 a particular encoder board or library. Then add the appropriate
 #define near the top of the main ROSArduinoBridge.ino file.
 
 ************************************************************ */

#ifdef USE_BASE


#if defined BOT
#include "motor_driver.h"
#include "commands.h";
volatile long encoderLeft = 0L;
volatile long encoderRight = 0L;
//ISRs for the encoders
void initEncoders(){
  attachInterrupt(encoderRightPin, encoderRightISR, CHANGE); 
  attachInterrupt(encoderLeftPin, encoderLeftISR, CHANGE);
  
}
void encoderRightISR(){
  //Serial.println("Right ISR");
  if(direction(RIGHT) == BACKWARDS){
    encoderRight--;
  }
  else{
    encoderRight++;
  }
}
void encoderLeftISR(){
  //Serial.println("Left ISR");
  if(direction(LEFT) == BACKWARDS){
    encoderLeft--;
  }
  else{
    encoderLeft++;
  }
}
long readEncoder(int i) {
  long encVal = 0L;
  if (i == LEFT)  {
    noInterrupts();//to avoid read errors
    encVal = encoderLeft;
    interrupts();
  }
  else {
    noInterrupts();
    encVal = encoderRight;
    interrupts();
  }
  return encVal;
}



/* Wrap the encoder reset function */
void resetEncoder(int i) {
  if (i == LEFT) encoderLeft = 0L;
  else encoderRight = 0L;
}
/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}
#else
#error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */


#endif

