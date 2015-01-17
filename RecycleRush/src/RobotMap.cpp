// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::chassisLeftMotor = NULL;
SpeedController* RobotMap::chassisRightMotor = NULL;
RobotDrive* RobotMap::chassisDriveMotors = NULL;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	chassisLeftMotor = new Talon(0);
	lw->AddActuator("Chassis", "LeftMotor", (Talon*) chassisLeftMotor);
	
	chassisRightMotor = new Talon(1);
	lw->AddActuator("Chassis", "RightMotor", (Talon*) chassisRightMotor);
	
	chassisDriveMotors = new RobotDrive(chassisLeftMotor, chassisRightMotor);
	
	chassisDriveMotors->SetSafetyEnabled(true);
        chassisDriveMotors->SetExpiration(0.1);
        chassisDriveMotors->SetSensitivity(0.5);
        chassisDriveMotors->SetMaxOutput(1.0);
        


	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
