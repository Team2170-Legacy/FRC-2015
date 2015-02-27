// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RotateWithBumpersLeft.h"
#include "ChassisRotate.h"
#include "../Subsystems/Chassis.h"

RotateWithBumpersLeft::RotateWithBumpersLeft() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	ChassisRotate::mRotateAngle = -90.0;
	mDriverControl = new Xbox360(Robot::oi->getJoystickDriverOnPort0());
}

// Called just before this Command runs the first time
void RotateWithBumpersLeft::Initialize() {
	ChassisRotate::Initialize();
}

// Called repeatedly when this Command is scheduled to run
void RotateWithBumpersLeft::Execute() {
	ChassisRotate::Execute();
}

// Make this return true when this Command no longer needs to run execute()
bool RotateWithBumpersLeft::IsFinished() {
	bool rVal = false;
	float LeftStick = mDriverControl->GetLeftY();
	float RightStick = mDriverControl->GetRightY();

	if ((DEADBAND(LeftStick, 0.075) != 0.0) || (DEADBAND(RightStick, 0.075) != 0.0)) {
		rVal = true;
	}
	else {
		rVal =  ChassisRotate::IsFinished();
	}

	return rVal;
}

// Called once after isFinished returns true
void RotateWithBumpersLeft::End() {
	ChassisRotate::End();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateWithBumpersLeft::Interrupted() {
	ChassisRotate::Interrupted();
}
