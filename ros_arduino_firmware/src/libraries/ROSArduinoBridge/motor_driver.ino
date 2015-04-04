/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
   
#if defined POLOLU_VNH5019
  /* Include the Pololu library */
  #include "DualVNH5019MotorShield.h"

  /* Create the motor driver object */
  DualVNH5019MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined POLOLU_MC33926
  /* Include the Pololu library */
  #include "DualMC33926MotorShield.h"

  /* Create the motor driver object */
  DualMC33926MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }

#elif defined BOT
void initMotorController() {
Servo sabertoothRightChannel;
Servo sabertoothLeftChannel;
sabertoothRightChannel.attach(sabertoothRightPin, 1000, 2000);
sabertoothLeftChannel.attach(sabertoothLeftPin, 1000, 2000);
sabertoothRightChannel.write(90);
sabertoothLeftChannel.write(90);
attachInterrupt(interruptRightPin, encoderRightISR, CHANGE);
attachInterrupt(interruptLeftPin, encoderLeftISR, CHANGE);
}

void setMotorSpeed(int i, int spd) {
if (i == LEFT){
if(spd < 90){
directionLeft == BACKWARDS;
}else{
directionLeft == FORWARDS;
}
sabertoothLeftChannel.write(constrain(spd, MINSABERTOOTH, MAXSABERTOOTH));
}else{
if(spd < 90){
directionRight == BACKWARDS;
}else{
directionRight == FORWARDS;
}
sabertoothRightChannel.write(constrain(spd, MINSABERTOOTH, MAXSABERTOOTH));
}
}
// A convenience function for setting both motor speeds
void setMotorSpeeds(int leftSpeed, int rightSpeed) {
setMotorSpeed(LEFT, leftSpeed);
setMotorSpeed(RIGHT, rightSpeed);
}

#else
  #error A motor driver must be selected!
#endif

#endif
