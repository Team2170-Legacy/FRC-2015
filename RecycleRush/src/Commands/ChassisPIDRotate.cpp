// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ChassisPIDRotate.h"

#define ROTATE_P 0.030f
#define ROTATE_I 0.001f
#define ROTATE_D 0.00225f

#define SET_WAIT_COUNT 20		// times to wait for ontarget to be true

ChassisPIDRotate::ChassisPIDRotate() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

ChassisPIDRotate::ChassisPIDRotate(float Angle) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::chassis);
	mAngle = Angle;
}

// Called just before this Command runs the first time
void ChassisPIDRotate::Initialize() {
	Robot::chassis->ResetChassisYaw();

	rotate = new SimplePIDOutput();
	turn = new PIDController(ROTATE_P, ROTATE_I, ROTATE_D, Robot::chassis->yawGyro, rotate, 0.01);

	turn->SetSetpoint(mAngle);
	turn->SetAbsoluteTolerance(1.0f);
	turn->SetOutputRange(-1.0, 1.0);
	turn->SetContinuous(false);
	turn->Enable();

	OnTargetCount = 0;
}

// Called repeatedly when this Command is scheduled to run
void ChassisPIDRotate::Execute() {
	Robot::chassis->driveMotors->Drive(rotate->getValue(), 1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool ChassisPIDRotate::IsFinished() {
	if (turn->OnTarget()) {
		OnTargetCount++;
	}
	else {
		OnTargetCount = 0;
	}
	return (OnTargetCount > SET_WAIT_COUNT);
}

// Called once after isFinished returns true
void ChassisPIDRotate::End() {
	turn->Disable();
	delete turn;
	delete rotate;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChassisPIDRotate::Interrupted() {

}