// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ChassisDriveStraightForTime.h"
#include <iostream>

ChassisDriveStraightForTime::ChassisDriveStraightForTime() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
ChassisDriveStraightForTime::ChassisDriveStraightForTime(float NewTime)
{
	Requires(Robot::chassis);

	mDriveTime = NewTime;


}

// Called just before this Command runs the first time
void ChassisDriveStraightForTime::Initialize() {
	Command::SetTimeout(mDriveTime);
	Robot::chassis->ResetChassisYaw();

}

// Called repeatedly when this Command is scheduled to run
void ChassisDriveStraightForTime::Execute() {
	Robot::chassis->DriveStraight();
	float TimeHolder;
	//Gets the inputted time
	TimeHolder = SmartDashboard::GetNumber("ChassisDriveStraightForTimeInput");
	//Outputs what was inputted
	SmartDashboard::PutNumber("TimeInputted", TimeHolder);
	//Sets the range for the input
	TimeHolder = fmin(fmax(TimeHolder, 0), 15);
	//Sets the new drive time according to the outputted variable which was formatted to the range
	mDriveTime = TimeHolder;
	//Displays the new number
	SmartDashboard::PutNumber("ChassisDriveStraightForTimeInput", TimeHolder);
	//Sets the timeout with the new number
	Command::SetTimeout(mDriveTime);
}

// Make this return true when this Command no longer needs to run execute()
bool ChassisDriveStraightForTime::IsFinished() {

	return Command::IsTimedOut();
}

// Called once after isFinished returns true
void ChassisDriveStraightForTime::End() {
	Robot::chassis->StopMotors();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChassisDriveStraightForTime::Interrupted() {


}
