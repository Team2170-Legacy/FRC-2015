/*
 * MotionData.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: nollchr
 */

#include "MotionData.h"

MotionData::MotionData() {
	// TODO Auto-generated constructor stub
}

MotionData::MotionData(Accelerometer* accel) {
	mAccel = accel;
}

MotionData::~MotionData() {
	// TODO Auto-generated destructor stub
}

void MotionData::UpdateData() {
	double accel = mAccel->GetY();
	double dT = UpdateTimer.Get();

	mAcceleration[1] = accel * GsToMeters;;
	mVelocity[1] = mVelocity[0] + mAcceleration[0] +
			((mAcceleration[1] - mAcceleration[0])/2.0) * dT;
	mDistance[1] = mDistance[0] + mVelocity[0] +
			((mVelocity[1] - mVelocity[0])/2.0) * dT;

	mAcceleration[0] = mAcceleration[1];
	mVelocity[0] = mVelocity[1];
	mDistance[0] = mDistance[1];
	mOdometer += mDistance[0];
	UpdateTimer.Reset();
}

void MotionData::Start() {
	UpdateTimer.Start();
}
void MotionData::ResetDistance() {
	mDistance[0] = 0.0;
	mDistance[1] = 0.0;
}

void MotionData::ResetOdometer() {
	mOdometer = 0.0;
}

double MotionData::GetDistance() {
	return mDistance[0];
}

double MotionData::GetVelocity() {
	return mVelocity[0];
}

double MotionData::GetOdometer() {
	return mOdometer;
}

double MotionData::GetAcceleration() {
	return mAcceleration[0];
}

void MotionData::Stop() {
	mAcceleration[0] = 0.0;
	mVelocity[0] = 0.0;
	mDistance[0] = 0.0;
	mAcceleration[1] = 0.0;
	mVelocity[1] = 0.0;
	mDistance[1] = 0.0;
	UpdateTimer.Stop();
	UpdateTimer.Reset();
}
