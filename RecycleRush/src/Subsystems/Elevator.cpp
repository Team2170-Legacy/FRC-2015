// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Elevator.h"
#include "../RobotMap.h"
#include "../OI.h"
#include "Math.h"
#include "../Robot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Elevator::Elevator() : Subsystem("Elevator") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	shaftEncoder = RobotMap::elevatorShaftEncoder;
	motor = RobotMap::elevatorMotor;
	lowerLimit = RobotMap::elevatorLowerLimit;
	upperLimit = RobotMap::elevatorUpperLimit;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	shaftEncoder->Reset();
	targetLevel = 0;
	distanceBetweenLevels = 1000;//FIND THIS
}
    
void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

//float TargetLevel = currentLevel + distanceBetweenLevels; //have this round to nearest multiple of distance between levels later
//currentLevel = shaftEncoder->Get();


bool Elevator::GetLowerSafety(){
	return lowerLimit->Get();//True when pushed
}

bool Elevator::GetUpperSafety(){
	return upperLimit->Get();//True when pushed
}

float Elevator::GetCurrentPosition(){
	if (GetLowerSafety()){
		shaftEncoder->Reset();
	}

	return shaftEncoder->GetDistance();
}

void Elevator::AddOneLevel(){
	targetLevel = int(GetCurrentPosition() / distanceBetweenLevels)*distanceBetweenLevels;

	targetLevel = fmin(targetLevel + distanceBetweenLevels, 4 * distanceBetweenLevels);
}

void Elevator::SubtractOneLevel(){
	targetLevel = int((GetCurrentPosition() / distanceBetweenLevels)+1.0)*distanceBetweenLevels;

	targetLevel = fmax(targetLevel - distanceBetweenLevels, 0);
}


bool Elevator::isMoving(){
	return (motor->Get() != 0.00);
}

bool Elevator::isAboveTarget() {
	return GetCurrentPosition() >= targetLevel;
}

bool Elevator::isBelowTarget() {
	return GetCurrentPosition() <= targetLevel;
}

void Elevator::ManualControl() {
	if (GetUpperSafety()){
		motor->Set(fmin(Robot::oi->getJoystickGunnerOnPort1()->GetRawAxis(2),0));
	}else if(GetLowerSafety()){
		motor->Set(fmax(Robot::oi->getJoystickGunnerOnPort1()->GetRawAxis(2),0));
	}else{
	motor->Set(Robot::oi->getJoystickGunnerOnPort1()->GetRawAxis(2));
	}
	SmartDashboardOutputs();

}

void Elevator::SmartDashboardOutputs() {
	SmartDashboard::PutNumber("CurrentPosition", GetCurrentPosition());
	SmartDashboard::PutNumber("TargetLevel", targetLevel);
}

void Elevator::RampUp(float direction, float MaxSpeed,  float RampRate){
	motor->Set(direction * fmin( (1+RampRate) * MaxSpeed, MaxSpeed));
}

void Elevator::RampDown(float direction,  float MinSpeed, float RampRate){
	motor->Set(direction * fmax( (1-RampRate) * MinSpeed, MinSpeed));
}

void Elevator::Stop(){
	motor->Set(0.00);
}
