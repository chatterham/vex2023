using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor frontLeftMotor;
extern motor backLeftMotor;
extern motor frontRightMotor;
extern motor backRightMotor;
extern motor flyWheel1;
extern motor flyWheel2;
extern motor intakeMotor;
extern motor rollerMotor;
extern controller Controller1;
extern digital_out indexer;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );