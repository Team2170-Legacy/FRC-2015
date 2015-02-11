/*
 * LowPassFilter.h
 *
 *  Created on: Feb 8, 2015
 *      Author: nollchr
 */

#ifndef SRC_LOWPASSFILTER_H_
#define SRC_LOWPASSFILTER_H_

class LowPassFilter {
private:
	double fCurrentOutput = 0.0;
	double fAlpha = 0.0;
	double CalculateAlpha(double fCutoffHz, double fSampleRateHz);
public:
	LowPassFilter();
	LowPassFilter(double fCutoffHz, double fSampleRateHz);
	double Update(double fNewVal);
	double GetCurrentValue();
	void Reset(void);
	virtual ~LowPassFilter();
};

#endif /* SRC_LOWPASSFILTER_H_ */
