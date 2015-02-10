// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include <iostream>
#include <cstdlib>
#include "Chassis.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/DriveWithJoysticks.h"
#include "../Commands/ChassisRotate.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Chassis::Chassis() : Subsystem("Chassis")
{
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftMotor = RobotMap::chassisLeftMotor;
	rightMotor = RobotMap::chassisRightMotor;
	driveMotors = RobotMap::chassisDriveMotors;
	yawGyro = RobotMap::chassisYawGyro;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	internalAccel = new BuiltInAccelerometer();

}

void Chassis::TankDriveWithTriggers(float Left, float Right, float Trigger){
	float newLeft = 0.0;
	float newRight = 0.0;
	float OriginalLeft = 0.0;
	float OriginalRight = 0.0;
	bool bSwapDirection = false;

	if (bSwapDirection == false) {
		if (fabs(Left) >= .1) {
			OriginalLeft = Left;
		}
		if (fabs(Right) >= .1) {
			OriginalRight = Right;
		}
	} else {
		if (fabs(Left) >= .1) {
			OriginalRight = Left;
		}
		if (fabs(Right) >= .1) {
			OriginalLeft = Right;
		}
	}
	newLeft = fmax(fmin(OriginalLeft + (Trigger * .8), 1.0), -1.0);
	newRight = fmax(fmin(OriginalRight + (Trigger * .8), 1.0), -1.0);

	driveMotors->TankDrive(newLeft, newRight, false);
}
    
void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new DriveWithJoysticks());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
//// here. Call these from Commands.

void Chassis::StopMotors(void)
{
	// Send zero to the driveMotors controller for both left and right .i.e. stop the motors
	driveMotors->StopMotor();

	mCurrentAutoMagnitude = mDefaultAutoMagnitude;
	mCurrentAutoRotationVelocity = mDefaultAutoRotatationVelocity;
}

void Chassis::DriveStraight()
{
	// Drive chassis straight for specified time
	Robot::chassis->driveMotors->SetSensitivity(0.1);
	float ChassisAngle = ReadChassisYaw();

	driveMotors->Drive(mAutoVelocity, mYawGain * ChassisAngle);
}

void Chassis::TurnClockwise()
{
	// Rotate chassis by specified degrees
	Robot::chassis->driveMotors->SetSensitivity(1.0);
	driveMotors->Drive(mCurrentAutoMagnitude, mCurrentAutoRotationVelocity);

}
void Chassis::TurnCounterclockwise()
{
	// Rotate chassis by specified degrees
	Robot::chassis->driveMotors->SetSensitivity(1.0);
	driveMotors->Drive(mCurrentAutoMagnitude, -1 * mCurrentAutoRotationVelocity);
}

void Chassis::ResetChassisYaw()
{
	//Resets gyro to 0
	yawGyro->Reset();
}

float Chassis::ReadChassisYaw()
{
	//Finds angle of robot's turn
	return yawGyro->GetAngle();
}

void Chassis::CalibrateChassis(){
	//Perform any one time chassis related calibrations
	yawGyro->InitGyro();
}

float Chassis::getCurrentAutoMagnitude() const {
	return mCurrentAutoMagnitude;
}

void Chassis::setCurrentAutoMagnitude(float currentAutoMagnitude) {
	mCurrentAutoMagnitude = currentAutoMagnitude;
}

float Chassis::getCurrentAutoRotationVelocity() const {
	return mCurrentAutoRotationVelocity;
}

void Chassis::setCurrentAutoRotationVelocity(float currentAutoRotationVelocity) {
	mCurrentAutoRotationVelocity = currentAutoRotationVelocity;
}
