// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "../MotionData.h"
#include "../MaxSonarEZ1.h"
#include "../LowPassFilter.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Chassis: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	float mAutoVelocity = 0.4;
	const float mDefaultAutoRotatationVelocity = 1.0;
	const float mDefaultAutoMagnitude = 0.3;
	float mCurrentAutoRotationVelocity = 1.0;
	float mCurrentAutoMagnitude = 0.3;
	float mYawGain = -0.2;
	LowPassFilter* LeftStickFilter;
	LowPassFilter* RightStickFilter;

	double AxisPower(double axis, double exponent);

	const bool bSwapDirection = true;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SpeedController* leftMotor;
	SpeedController* rightMotor;
	RobotDrive* driveMotors;
	Gyro* yawGyro;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	BuiltInAccelerometer* internalAccel;
	MotionData* movementData;
	MaxSonarEZ1* payloadRange;

	Chassis();
	void InitDefaultCommand();

	void StopMotors();

	void DriveStraight();
	void TurnClockwise();
	void TurnCounterclockwise();

	void ResetChassisYaw();
	float ReadChassisYaw();
	void CalibrateChassis();

	void TankDriveWithTriggers(float Left, float Right, float Trigger);

	float getCurrentAutoMagnitude() const;
	void setCurrentAutoMagnitude(float currentAutoMagnitude = -0.3);
	float getCurrentAutoRotationVelocity() const;
	void setCurrentAutoRotationVelocity(float currentAutoRotationVelocity = 1.0);
};

#endif
