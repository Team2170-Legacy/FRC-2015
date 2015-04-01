/*
 * SimplePIDOutput.h
 *
 *  Created on: Mar 20, 2015
 *      Author: nollchr
 */

#include "wpilib.h"

#ifndef SRC_SimplePIDOUTPUT_H_
#define SRC_SimplePIDOUTPUT_H_

class SimplePIDOutput : public PIDOutput {
private:
	float mValue = 0.0f;
public:
	SimplePIDOutput();
	void PIDWrite(float output);
	float getValue();
	virtual ~SimplePIDOutput();
};

#endif /* SRC_SimplePIDOUTPUT_H_ */
