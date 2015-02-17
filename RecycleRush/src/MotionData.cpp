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
	double accel = DEADBAND(mAccel->GetX(), 0.05);
	double dT = UpdateTimer.Get();

	mAcceleration += accel * GsToMeters;;
	mVelocity += mAcceleration * dT;
	mDistance += mVelocity * dT;
	mOdometer += mVelocity * dT;
	UpdateTimer.Reset();
}

void MotionData::Start() {
	UpdateTimer.Start();
}
void MotionData::ResetDistance() {
	mDistance = 0.0;
}

void MotionData::ResetOdometer() {
	mOdometer = 0.0;
}

double MotionData::GetDistance() {
	return mDistance;
}

double MotionData::GetVelocity() {
	return mVelocity;
}

double MotionData::GetOdometer() {
	return mOdometer;
}

double MotionData::GetAcceleration() {
	return mAcceleration;
}

void MotionData::Stop() {
	mAcceleration = 0.0;
	mVelocity = 0.0;
	mDistance = 0.0;
	UpdateTimer.Stop();
	UpdateTimer.Reset();
}
