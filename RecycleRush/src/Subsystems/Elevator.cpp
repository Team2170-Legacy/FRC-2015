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
	//shaftEncoder->Reset();
	targetLevel = 0;
	distanceBetweenLevels = 654;//FIND THIS
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
	return !lowerLimit->Get();//True when pushed
}

bool Elevator::GetUpperSafety(){
	return !upperLimit->Get();//True when pushed
}



float Elevator::GetCurrentPosition(){
	if (GetLowerSafety()){
		shaftEncoder->Reset();
	}

	return shaftEncoder->GetDistance();
}

void Elevator::AddOneLevel(){

	SmartDashboardInputs();
	SmartDashboardOutputs();

	targetLevel = round(GetCurrentPosition() / distanceBetweenLevels)*distanceBetweenLevels;
	targetLevel = fmin(targetLevel + distanceBetweenLevels, 4 * distanceBetweenLevels);
}

void Elevator::SubtractOneLevel(){

	SmartDashboardInputs();
	SmartDashboardOutputs();

	targetLevel = (round((GetCurrentPosition() / distanceBetweenLevels)))*distanceBetweenLevels;
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

float Elevator::GetSpeed() {
	return motor->Get();
}

float Elevator::GetThrottle() {

return  ( ( (Robot::oi->getJoystickGunnerOnPort1()->GetRawAxis(2)) - 1.0) / -2.0);
}


void Elevator::ManualControl() {
	if (GetUpperSafety()){
		motor->Set(fmin(Robot::oi->getJoystickGunnerOnPort1()->GetRawAxis(1)* GetThrottle(),0));
	}else 	if (GetLowerSafety()){
		motor->Set(fmax(Robot::oi->getJoystickGunnerOnPort1()->GetRawAxis(1)*GetThrottle(),0));
	}else{
		motor->Set(Robot::oi->getJoystickGunnerOnPort1()->GetRawAxis(1)*GetThrottle());
	}


	SmartDashboardOutputs();

}

void Elevator::SmartDashboardInputs() {
	// Gets the distanceBetweenLevels number from SmartDashboard and range checks it and displays it

	distanceBetweenLevels = SmartDashboard::GetNumber("distanceBetweenLevels");
	distanceBetweenLevels = fmin(fmax(distanceBetweenLevels,0),5000);
}

void Elevator::SmartDashboardOutputs() {
	SmartDashboard::PutNumber("CurrentPosition", GetCurrentPosition());
	SmartDashboard::PutNumber("TargetLevel", targetLevel);
	SmartDashboard::PutNumber("distanceBetweenLevels", distanceBetweenLevels);
}

void Elevator::RampUp( float MaxSpeed,  float RampRate){
	motor->Set( fmax( fmin( (1+RampRate) * motor->Get(), MaxSpeed), -1* MaxSpeed) ) ;
}

void Elevator::RampDown(  float MinSpeed, float RampRate){
	if (MinSpeed > 0){
	motor->Set( fmax((1-RampRate) * motor->Get(), MinSpeed ));
	}else{
	motor->Set( fmin((1-RampRate) * motor->Get(), -1*MinSpeed ));
	}
}

void Elevator::RampCombined(float MinSpeed, float MaxSpeed, float RampRate) {
	if (abs( GetCurrentPosition() - targetLevel ) < (.4 * distanceBetweenLevels)) {
		RampDown( MinSpeed, RampRate);
	}else{
		RampUp(MaxSpeed, RampRate);
	}
}

void Elevator::SetTargetLevel(float TargetLevel){
	targetLevel = TargetLevel;
}

void Elevator::Start(float speed){
	motor->Set(speed);
}


void Elevator::Stop(){
	motor->Set(0.00);
}
