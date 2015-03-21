/*
 * SimplePIDOutput.cpp
 *
 *  Created on: Mar 20, 2015
 *      Author: nollchr
 */

#include "SimplePIDOutput.h"

SimplePIDOutput::SimplePIDOutput() {
	// TODO Auto-generated constructor stub

}

void SimplePIDOutput::PIDWrite(float output) {
	mValue = output;
}

float SimplePIDOutput::getValue() {
	return mValue;
}

SimplePIDOutput::~SimplePIDOutput() {
	// TODO Auto-generated destructor stub
}

