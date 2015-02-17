/*
 * MotionData.h
 *
 *  Created on: Feb 7, 2015
 *      Author: nollchr
 */

#ifndef SRC_MOTIONDATA_H_
#define SRC_MOTIONDATA_H_

#include "WPILib.h"

#define DEADBAND(val, limit)	((fabs(val) < limit) ? 0.0 : val)


class MotionData {
private:
	double mAcceleration = 0.0;
	double mVelocity = 0.0;
	double mDistance = 0.0;
	double mOdometer = 0.0;
	Accelerometer* mAccel = nullptr;
	Timer UpdateTimer;
	double mDeltaTime = (1.0 / 50.0);			// 50 Hz (20 msec)
	const double GsToMeters = 9.80665;	// Gs to Meters/S^2

public:
	MotionData();
	MotionData(Accelerometer* accel);
	virtual ~MotionData();
	void UpdateData();
	void ResetDistance();
	void ResetOdometer();
	double GetDistance();
	double GetVelocity();
	double GetOdometer();
	double GetAcceleration();
	void Start();
	void Stop();
};

#endif /* SRC_MOTIONDATA_H_ */
