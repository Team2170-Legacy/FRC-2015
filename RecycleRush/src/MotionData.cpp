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
	mAcceleration += mAccel->GetY() * GsToMeters;;
	mVelocity += mAcceleration * mDeltaTime;
	mDistance += mVelocity * mDeltaTime;
	mOdometer += mVelocity * mDeltaTime;
}

void MotionData::ResetDistance() {
	mDistance = 0.0;
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
}
