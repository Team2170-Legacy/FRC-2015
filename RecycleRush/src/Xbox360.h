#ifndef XBOX360_H_
#define XBOX360_H_

#include <Joystick.h>
#include <cstddef>



/**
 * This class is designed to interface with an Xbox 360 controller to allow
 * it to control the robot. It contains functions which will access
 * all of the buttons and throttles on the controller.
 * 
 * This class uses the Joystick class to interface with the Drivers Station
 * to get the input from the controller
 * 
 * This class relies on the library "CustomMath" which Team 2022 developed
 * to provide a complete math library. Please edit the include line to match
 * its location 
 */
class Xbox360
{


public:
	explicit Xbox360(Joystick* NewJoystick);
	
	double GetLeftX();
	double GetLeftY();
	double GetRightX();
	double GetRightY();
	
	double GetTriggers();
	
	bool GetA();
	bool GetB();
	bool GetX();
	bool GetY();
	bool GetLeftBumper();
	bool GetRightBumper();
	bool GetBack();
	bool GetStart();
	
private:
	float GetRawAxis(unsigned int axis);
	bool GetRawButton(unsigned int button);
	double Limit(double num);
	Joystick* mJoystick = NULL;
};

#endif
