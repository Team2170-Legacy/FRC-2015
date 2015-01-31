// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ChassisRotate.h"
#include <iostream>

ChassisRotate::ChassisRotate() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

ChassisRotate::ChassisRotate(float NewAngle)
{
	Requires(Robot::chassis);

	mRotateAngle = NewAngle;

}

// Called just before this Command runs the first time
void ChassisRotate::Initialize() {
	Command::SetTimeout(5.0);
	Robot::chassis->ResetChassisYaw();

}

// Called repeatedly when this Command is scheduled to run
void ChassisRotate::Execute() {
	std::cout << "Rotate Execute\n";
	if (mRotateAngle > 0)
		Robot::chassis->TurnClockwise();
	else if (mRotateAngle < 0)
		Robot::chassis->TurnCounterclockwise();
	else
		End();
}

// Make this return true when this Command no longer needs to run execute()
bool ChassisRotate::IsFinished() {

	float CurrentAngle = Robot::chassis->ReadChassisYaw();
	if (fabs(CurrentAngle) >= fabs(mRotateAngle))
		return true;
	else if (Command::IsTimedOut())
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void ChassisRotate::End() {
	Robot::chassis->StopMotors();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChassisRotate::Interrupted() {
	std::cout << "Rotate Interrupted\n";

}
