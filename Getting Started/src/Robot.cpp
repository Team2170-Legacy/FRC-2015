#include "WPILib.h"
// Change #1
// Change #2
// Change #3
// Change #4 from Mr. R machine
// Change #5 from L01 machine
// Change #6 from L02 machine
// Change #7
// Change #8 Ethan
// Change #9 Patrick
// Change #10 Tushar
// Change #11 Rahul
// Change #12 Mr. Rudolph after Pull issue resolved - test #1
// Change #13 Mr. Rudolph after Pull issue resolved - test #2
// Change #14 Mr. Rudolph after Pull issue resolved - test #3
// Change #15 Mr. Rudolph after repository restore - test #1
// Change #16 Mr. Rudolph after repository restore - test #2
// Change #18 Mr. Rudolph after repository restore - test #3
// Change #19 C. Noll rocks....
// Change #20 Nick Maglio is better....
// Change #21 Tushar disappoints worldwide
// Change #22 Testing Testing Testing
// Change #23 Rahul Narain hopes this works
class Robot: public IterativeRobot
{

	RobotDrive myRobot; // robot drive system
	Joystick stick; // only joystick
	LiveWindow *lw;
	int autoLoopCounter;

public:
	Robot() :
		myRobot(0, 1),	// these must be initialized in the same order
		stick(0),		// as they are declared above.
		lw(NULL),
		autoLoopCounter(0)
	{
		myRobot.SetExpiration(0.1);
	}

private:
	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
	}

	void AutonomousInit()
	{
		autoLoopCounter = 0;
	}

	void AutonomousPeriodic()
	{
		if(autoLoopCounter < 100) //Check if we've completed 100 loops (approximately 2 seconds)
		{
			myRobot.Drive(-0.5, 0.0); 	// drive forwards half speed
			autoLoopCounter++;
			} else {
			myRobot.Drive(0.0, 0.0); 	// stop robot
		}
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
