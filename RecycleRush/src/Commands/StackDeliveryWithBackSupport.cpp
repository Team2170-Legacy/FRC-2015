// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "StackDeliveryWithBackSupport.h"
#include "ArmOpen.h"
#include "ChassisDriveStraightForDistance.h"
#include "ChassisDriveStraightForDistanceAccelDecel.h"
#include "ElevatorGotoPosition.h"
#include "ElevatorPlatformStage.h"
#include "ElevatorPlatformPlaceWithPower.h"

StackDeliveryWithBackSupport::StackDeliveryWithBackSupport() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,  a CommandGroup containing them would require both the chassis and the arm.

	AddParallel(new ElevatorPlatformStage());										// Lift the stack to just above scoring platform
	AddSequential(new ChassisDriveStraightForDistanceAccelDecel(22.75, 0.35, true, 0.5, 3.0));	// Drive to stack drop location
	AddSequential(new WaitCommand(0.50));											// Wait for can to settle down from driving
	AddSequential(new ElevatorPlatformPlaceWithPower());							// Put the stack down gently
	AddParallel(new ArmOpen());														// Open the arms
//	AddSequential(new WaitCommand(0.250));											// Wait for arms to finish opening
//	AddSequential(new ChassisDriveStraightForDistance(-(11.375 - 2.0), -0.50, true));// Back away from stack


//	AddParallel(new ElevatorPlatformStage());											// Lift the stack to just above scoring platform
//	AddSequential(new ChassisDriveStraightForDistance(11.45, 0.25, true));				// Drive to ready for partial drop
//	AddSequential(new ElevatorGotoPosition( 800.0 - 54*0.5 ));							// Partial stack drop, onto back support and scoring platform
//	AddSequential(new ChassisDriveStraightForDistance(18.75 - 11.45, 0.25, true));		// Drive to final stack drop location
//	AddSequential(new ElevatorPlatformPlace());											// Put the stack down
//	AddParallel(new ArmOpen());															// Open the arms
//	AddSequential(new WaitCommand(0.250));												// Wait for arms to finish opening
//	AddSequential(new ChassisDriveStraightForDistance(-(18.75 - 4.0), -0.50, true));	// Back away from stack
}
