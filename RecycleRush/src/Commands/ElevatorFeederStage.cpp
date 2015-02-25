// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "ElevatorFeederStage.h"
#include "ElevatorGotoPosition.h"

ElevatorFeederStage::ElevatorFeederStage() {

	// Move Arm to tote level 3.5.
	// Room for feeder station totes to slide diagonally onto single floor tote and not hit carried stack
//	AddSequential(new ElevatorGotoPosition( 654.0*3.5 ));		// Initial estimate 2289
	AddSequential(new ElevatorGotoPosition( 1783 ));		// Initial estimate 2289
}
