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
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Elevator::Elevator() : Subsystem("Elevator") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	encoder = RobotMap::elevatorEncoder;
	talon = RobotMap::elevatorTalon;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

// 2170 code
void Elevator::Init() {
	encoder->Reset();

	// Below copied from FIRST Encoder sample project
	// Defines the number of samples to average when determining the rate.
	// On a quadrature encoder, values range from 1-255; larger values
	//   result in smoother but potentially less accurate rates than lower values.
	encoder->SetSamplesToAverage(5);

	// Defines how far the mechanism attached to the encoder moves per pulse.
	// In this case, we assume that a 360 count encoder is directly attached
	//   to a 3 inch diameter (1.5inch radius) wheel, and that we want to
	//   measure distance in inches.
	encoder->SetDistancePerPulse(1.0);
//	encoder->SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * 1.5);

	// Defines the lowest rate at which the encoder will not be considered
	//   stopped, for the purposes of the GetStopped() method.
	// Units are in distance / second, where distance refers to the units
	//   of distance that you are using, in this case inches.
	encoder->SetMinRate(1.0);

}

// 2170 code
double Elevator::GetDistance() {
	return encoder->GetDistance();
}

// 2170 code
void Elevator::SetSpeed(float speed) {
		talon->Set(speed);
}
