// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "DoubleSolenoid.h"
#include "Intake.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Intake::Intake() : Subsystem("Intake") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftMotor = RobotMap::intakeLeftMotor;
	rightMotor = RobotMap::intakeRightMotor;
	leftMotorTalon = RobotMap::intakeLeftMotorTalon;
	rightMotorTalon = RobotMap::intakeRightMotorTalon;
	doubleSolenoid = RobotMap::intakeDoubleSolenoid;
	toteReceivedLimit = RobotMap::intakeToteReceivedLimit;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

//kOff - Turns both relay outputs off
//kForward - Sets the relay to forward (M+ @ 12V, M- @ GND)
//kReverse - Sets the relay to reverse (M+ @ GND, M- @ 12V)
//kOn - Sets both relay outputs on (M+ @ 12V, M- @ 12V)

void Intake::StartBothSides(float direction) {
//	leftMotor->Set(direction);
//	rightMotor->Set(direction);
	leftMotorTalon->Set(direction);
	rightMotorTalon->Set(direction);
}

void Intake::StartLeftSide(float direction) {
	leftMotorTalon->Set(direction);
}

void Intake::StartRightSide(float direction) {
	rightMotorTalon->Set(direction);
}

void Intake::StopBothSides() {
//	leftMotor->Set(Relay::kOff);
//	rightMotor->Set(Relay::kOff);
	leftMotorTalon->Set(0.0);
	rightMotorTalon->Set(0.0);
}

void Intake::StopLeftSide() {
	leftMotor->Set(Relay::kOff);
}

void Intake::StopRightSide() {
	rightMotor->Set(Relay::kOff);
}

void Intake::Open(){
		doubleSolenoid->Set(DoubleSolenoid::kForward);
}

void Intake::Close(){
		doubleSolenoid->Set(DoubleSolenoid::kReverse);
}

void Intake::Reverse(){
	switch(doubleSolenoid->Get())
	{
		case DoubleSolenoid::kOff:
			Open();
			break;
		case DoubleSolenoid::kForward:
			Close();
			break;
		case DoubleSolenoid::kReverse:
			Open();
			break;
	}
}

