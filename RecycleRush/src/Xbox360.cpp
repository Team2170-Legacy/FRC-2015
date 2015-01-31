#include <Joystick.h>
#include "Xbox360.h"


/**
 * Creates an object to interace with an Xbox 360 controller
 * 
 * @param port The port on the drivers station that the controller is connected to
 */
Xbox360::Xbox360(unsigned int port) :
	Joystick(port) {
	//Do nothing
}

/**
 * Get the value of X of the left joystick.
 * The right side of the axis is positive.
 * 
 * @return The value of the axis from -1 to 1.
 */
double Xbox360::GetLeftX() {
	return (mJoystick->GetRawAxis(1));
}

/**
 * Get the value of Y of the left joystick.
 * The upward part of the axis is positive.
 * 
 * @return The value of the axis from -1 to 1.
 */
double Xbox360::GetLeftY() {
	return (-1 * mJoystick->GetRawAxis(2)); //Multiply output by -1 because GetAxis() returns the axis backwards.
}

/**
 * Get the value of X of the right joystick.
 * The right side of the axis is positive.
 * 
 * @return The value of the axis from -1 to 1.
 */
double Xbox360::GetRightX() {
	return (mJoystick->GetRawAxis(4));
}

/**
 * Get the value of Y of the right joystick.
 * The upward part of the axis is positive.
 * 
 * @return The value of the axis from -1 to 1.
 */
double Xbox360::GetRightY() {
	return (-1 * mJoystick->GetRawAxis(5));
}

/**
 * Get the value corresponding to the triggers.
 * The left stick adds to it, the right stick subtracts. Range -1 to 1.
 * 
 * @return The value corresponding to the triggers.
 */
double Xbox360::GetTriggers() {
	return (mJoystick->GetRawAxis(3));
}

/**
 * Get the current state of the A button.
 * 
 * @return The current state of the button
 */
bool Xbox360::GetA() {
	return (mJoystick->GetRawButton(1));
}

/**
 * Get the current state of the B button.
 * 
 * @return The current state of the button
 */
bool Xbox360::GetB() {
	return (mJoystick->GetRawButton(2));
}

/**
 * Get the current state of the X button.
 * 
 * @return The current state of the button
 */
bool Xbox360::GetX() {
	return (mJoystick->GetRawButton(3));
}

/**
 * Get the current state of the Y button.
 * 
 * @return The current state of the button
 */
bool Xbox360::GetY() {
	return (mJoystick->GetRawButton(4));
}

/**
 * Get the current state of the Left Bumper.
 * 
 * @return The current state of the button
 */
bool Xbox360::GetLeftBumper() {
	return (mJoystick->GetRawButton(5));
}

/**
 * Get the current state of the Right Bumper.
 * 
 * @return The current state of the button
 */
bool Xbox360::GetRightBumper() {
	return (mJoystick->GetRawButton(6));
}

/**
 * Get the current state of the Back button.
 * 
 * @return The current state of the button
 */
bool Xbox360::GetBack() {
	return (mJoystick->GetRawButton(7));
}

/**
 * Get the current state of the Start button.
 * 
 * @return The current state of the button
 */
bool Xbox360::GetStart() {
	return (mJoystick->GetRawButton(8));
}

/**
 * Get the buttons of the controller, to be used by other functions.
 *
 * The buttons on the controller follow this mapping
 * 1: A
 * 2: B
 * 3: X
 * 4: Y
 * 5: Left Bumper
 * 6: Right Bumper
 * 7: Back
 * 8: Start
 * 9: Left Joystick
 * 10: Right Joystick
 *
 * @param button The button to get the value of. Range 1-10.
 * @return The state of the button.
 */
bool Xbox360::GetRawButton(unsigned int button) {
	return (mJoystick->GetRawButton(button));
}

/**
 * Get the raw axes of the controller, to be used by other functions.
 * 
 * The axis on the controller follow this mapping
 * 1: Left Stick X Axis
 * 		-Left:Negative ; Right: Positive
 * 2: Left Stick Y Axis
 * 		-Up: Negative ; Down: Positive
 * 3: Triggers
 * 		-Left: Positive ; Right: Negative
 * 4: Right Stick X Axis
 * 		-Left: Negative ; Right: Positive
 * 5: Right Stick Y Axis
 * 		-Up: Negative ; Down: Positive
 * 6: Directional Pad (Not recommended, buggy)
 * 
 * @param axis The axis to get the value of. Range 1-6.
 * @return The value of the axis from -1 to 1.
 */
float Xbox360::GetRawAxis(unsigned int axis) {
	return (mJoystick->GetRawAxis(axis));
}

/**
 * Normalize outputs to be between -1 and 1.
 * 
 * @param num The value to normalize.
 * @return The normalized value.
 */
double Xbox360::Limit(double num) {
	if (num > 1) {
		num = 1;
	} else if (num < -1) {
		num = -1;
	}
	return num;
}

