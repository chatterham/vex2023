#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor frontLeftMotor = motor(PORT1, ratio18_1, false);
motor backLeftMotor = motor(PORT2, ratio18_1, false);
motor frontRightMotor = motor(PORT3, ratio18_1, false);
motor backRightMotor = motor(PORT4, ratio18_1, false);
motor flyWheel1 = motor(PORT10, ratio6_1, false);
motor flyWheel2 = motor(PORT11, ratio6_1, false);
motor intakeMotor = motor(PORT5, ratio18_1, false);
motor rollerMotor = motor(PORT6, ratio18_1, false);
controller Controller1 = controller(primary);
digital_out indexer = digital_out(Brain.ThreeWirePort.H);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}