// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef INTAKE_H
#define INTAKE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


/**
 *
 *
 * @author ExampleAuthor
 */
class Intake: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Relay* leftMotor;
	Relay* rightMotor;
	DoubleSolenoid* doubleSolenoid;
	DigitalInput* toteReceivedLimit;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Intake();
	void InitDefaultCommand();
	void StartBothSides(Relay::Value direction);
	void StartRightSide(Relay::Value direction);
	void StartLeftSide(Relay::Value direction);
	void StopBothSides();
	void StopRightSide();
	void StopLeftSide();
	void Open();
	void Close();
	void Reverse();
};

#endif
