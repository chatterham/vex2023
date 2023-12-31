/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// frontLeftMotor       motor         1               
// backLeftMotor        motor         2               
// frontRightMotor      motor         3               
// backRightMotor       motor         4               
// flyWheel1            motor         10              
// flyWheel2            motor         11              
// intakeMotor          motor         5               
// rollerMotor          motor         6               
// Controller1          controller                    
// indexer              digital_out   H               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
 
// A global instance of competition
competition Competition;
// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {

     
  frontLeftMotor.spin(reverse);

  frontRightMotor.spin(forward);

  backLeftMotor.spin(reverse);

  backRightMotor.spin(forward);

  rollerMotor.spin(forward);
   

   wait(800, msec);
   frontLeftMotor.stop();
   frontRightMotor.stop();
   backLeftMotor.stop();
   backRightMotor.stop();
   rollerMotor.stop();
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}
int flywheelSpeedModifier = 80;
  int speedL =80;
  int speedR =80;
  int speedMultipler = 1;
  double upDown = 0;
  double leftRight = 0;
  int speedEditor = speedMultipler/10;
  int intakeSpeed = 0;
  char progressBars[11][14]
        = { "----------","*---------","**--------","***-------","****------","*****-----","******----","*******---","********--","*********-","**********" };
 
void increaseSpeed()
{
  
  if(speedMultipler<10){
    
    Controller1.Screen.clearLine  (5);
    
    speedMultipler++;
    
    Controller1.Screen.print("hi");
    
    wait(10,sec);
    
  }else{
    Controller1.Screen.clearScreen();
    
    Controller1.Screen.print(progressBars[speedMultipler]);
  }
 
}

void decreaseSpeed()
{
  if(speedMultipler>0){
    
    speedMultipler--;
    Controller1.Screen.clearScreen();
    Controller1.Screen.print(progressBars[speedMultipler]);
    

    
  }else{
    Controller1.Screen.clearScreen();
    Controller1.Screen.print(progressBars[speedMultipler]);
  }
 
 
}

void increaseIntakeSpeed()
{
 
}

void decreaseIntakeSpeed()
{
  
}
 
  

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
 
  // User control code here, inside the loop
  while (1) {
    if(Controller1.ButtonDown.pressing()){

      
  frontLeftMotor.spin(reverse);

  frontRightMotor.spin(forward);

  backLeftMotor.spin(reverse);

  backRightMotor.spin(forward);
  
  rollerMotor.spin(forward);

   wait(3000, msec);
   frontLeftMotor.stop();
   frontRightMotor.stop();
   backLeftMotor.stop();
   backRightMotor.stop();
   rollerMotor.stop();
      
    }
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    upDown = Controller1.Axis3.position(percent);
    leftRight = (Controller1.Axis4.position(percent)*-1);
    


    if(Controller1.ButtonL1.pressing()){

      indexer.set(false);
      wait(200, msec);
      indexer.set(true);
     


    }
     if(Controller1.ButtonL2.pressing()){

    
      indexer.set(true);
     
      
    }
    if(Controller1.ButtonA.pressing()){

      
     intakeMotor.spin(reverse,100,percent);
     rollerMotor.spin(reverse,70,percent);
    
     


    }
     if(Controller1.ButtonB.pressing()){

    
      intakeMotor.stop();
     rollerMotor.stop();
      
    }
    if(Controller1.ButtonR1.pressing()){

      
      for(int i = 0;i <= 100;i++ ){
        i++;
        flyWheel1.spin(reverse,flywheelSpeedModifier,percent);
     
        flyWheel2.spin(forward,flywheelSpeedModifier,percent);
        wait(20,msec);
      

      }
     flyWheel1.spin(reverse,flywheelSpeedModifier,percent);
     
     flyWheel2.spin(forward,flywheelSpeedModifier,percent);
    
     


    }
     if(Controller1.ButtonR2.pressing()){

    
     flyWheel1.stop();
     
        flyWheel2.stop();
     
      
    }
    
    if(Controller1.ButtonY.pressing()){
        if(flywheelSpeedModifier==100){
          flywheelSpeedModifier = 80;

        }else if(flywheelSpeedModifier == 80){

           flywheelSpeedModifier = 30;
        }else{
          flywheelSpeedModifier = 100;
        }
        
      

    }
    
    
    //if(Controller1.ButtonX.pressing()){
   //   MotorGroup12.spin(directionType::fwd, 600, rpm);
  //  }
    

     

    frontLeftMotor.spin(forward,upDown+leftRight, percent);
    backLeftMotor.spin(forward,upDown+leftRight, percent);
    frontRightMotor.spin(reverse,upDown-leftRight, percent);
    backRightMotor.spin(reverse,upDown-leftRight, percent);
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//


int main() {
  
  // Set up callbacks for autonomous and driver control periods.
  indexer.set(true);
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  //void autonomous(void);

   
 
 

}


  























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































    
   