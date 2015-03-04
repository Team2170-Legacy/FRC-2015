// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutonomousPickupAndScore.h"
#include "ChassisDriveStraightForTime.h"
#include "ChassisRotate.h"
#include "ElevatorGotoPosition.h"
#include "ArmCalibrate.h"
#include "ElevatorAutoZero.h"
#include "IntakeCalibrate.h"
#include "ArmOpen.h"
#include "ArmClose.h"

AutonomousPickupAndScore::AutonomousPickupAndScore() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	AddSequential(new ArmOpen());
	AddSequential(new WaitCommand(0.5));	// wait for arm to open
	AddSequential(new ElevatorAutoZero());
	AddSequential(new ArmClose());
	AddSequential(new WaitCommand(0.5));		// wait for arm to close
	AddSequential(new ElevatorGotoPosition(700.0));
	AddSequential(new ChassisRotate(90.0));
	AddSequential(new WaitCommand(0.250));
	AddSequential(new ChassisRotate(90.0, true));
	AddSequential(new ChassisDriveStraightForTime(3.6));
	AddSequential(new ElevatorGotoPosition(0.0));
	AddSequential(new ArmOpen());
}
