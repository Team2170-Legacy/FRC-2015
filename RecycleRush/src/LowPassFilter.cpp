/*
 * LowPassFilter.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: nollchr
 */

#include "LowPassFilter.h"
#include <cmath>

LowPassFilter::LowPassFilter() {
	// TODO Auto-generated constructor stub

}

double LowPassFilter::CalculateAlpha(double fCutoffHz, double fSampleRateHz) {
	// cutoff = -ln(alpha) * (sample rate / 2PI)
	// alpha = exp(-2PI * cutoff / sample rate)
	return (exp(-2.0 * M_PI * fCutoffHz / fSampleRateHz));
}

LowPassFilter::LowPassFilter(double fCutoffHz, double fSampleRateHz) {
	fAlpha = CalculateAlpha(fCutoffHz, fSampleRateHz);
}

double LowPassFilter::Update(double fNewVal) {
	fCurrentOutput = fCurrentOutput + fAlpha * (fNewVal - fCurrentOutput);
	return fCurrentOutput;
}

void LowPassFilter::Reset(void) {
	fCurrentOutput = 0.0;
}

LowPassFilter::~LowPassFilter() {
	// TODO Auto-generated destructor stub
}

