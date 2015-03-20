// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutonomousPickupTwoTotesAndScore.h"
#include "ChassisDriveStraightForTime.h"
#include "ChassisRotate.h"
#include "ElevatorGotoPosition.h"
#include "ArmCalibrate.h"
#include "ElevatorAutoZero.h"
#include "IntakeCalibrate.h"
#include "IntakeOpenClose.h"
#include "IntakeOut.h"
#include "IntakeSpin.h"
#include "IntakeSpinLeft.h"
#include "ArmOpen.h"
#include "ArmClose.h"

#define	TOTE_RAISE_POSITION		831.0f
#define V_KNOCK_CAN		1.0f
#define V_COLLECT_TOTE	0.6f
#define V_FULL 1.0f

AutonomousPickupTwoTotesAndScore::AutonomousPickupTwoTotesAndScore() {
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

	AddSequential(new ArmOpen());									// open arms to pass around tote
	AddSequential(new IntakeCalibrate());							// opens intake
	AddSequential(new WaitCommand(0.5));							// wait for arm to open
	AddSequential(new ElevatorAutoZero());							// lower elevator
	AddSequential(new ArmClose());									// grab first tote
	AddSequential(new WaitCommand(0.5));							// wait for arm to close
	AddSequential(new ElevatorGotoPosition(TOTE_RAISE_POSITION));	// raise tote

	// tote #2
	AddSequential(new IntakeOpenClose());							// close intake
	AddParallel(new IntakeSpinLeft(), 1.0);						    // spin intake away from robot
	AddParallel(new ChassisDriveStraightForTime(1.0, V_KNOCK_CAN));	// move to next tote
	AddSequential(new IntakeOpenClose());							// open intake
	AddSequential(new ChassisDriveStraightForTime(0.5));			// approach 2nd tote
	AddParallel(new IntakeSpin(), 0.5);								// spin inward to pull tote
	AddParallel(new IntakeOpenClose());								// close intake to pull in bin
	AddSequential(new IntakeOpenClose());							// open intake
	AddSequential(new ElevatorGotoPosition(0.0));					// lower elevator to grab bottom
	AddSequential(new ElevatorGotoPosition(TOTE_RAISE_POSITION));	// raise stack of 2 totes

	// tote #3
	AddSequential(new IntakeOpenClose());							// close intake
	AddParallel(new IntakeOut(), 1.0);						        // spin intake away from robot
	AddParallel(new ChassisDriveStraightForTime(1.0, V_KNOCK_CAN));	// move to next tote
	AddSequential(new IntakeOpenClose());							// open intake
	AddSequential(new ChassisDriveStraightForTime(0.5));			// approach 2nd tote
	AddParallel(new IntakeSpin(), 0.5);								// spin inward to pull tote
	AddParallel(new IntakeOpenClose());								// close intake to pull in bin
	AddSequential(new IntakeOpenClose());							// open intake
	AddSequential(new ElevatorGotoPosition(0.0));					// lower elevator to grab bottom
	AddSequential(new ElevatorGotoPosition(TOTE_RAISE_POSITION));	// raise stack of 2 totes

	// go to autonomous scoring zone
	AddSequential(new ChassisRotate(90.0));
	AddSequential(new WaitCommand(0.250));
	AddSequential(new ChassisRotate(90.0, true));
	AddSequential(new ChassisDriveStraightForTime(2.0, V_FULL));
	AddSequential(new ElevatorGotoPosition(0.0));
	AddSequential(new ArmOpen());
	AddSequential(new ElevatorGotoPosition(500.0));


}
