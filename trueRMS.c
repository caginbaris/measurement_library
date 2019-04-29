
#include "mlib.h"


// True RMS half cycle
// delayLineArray contains full period circular data of input
// delayLineCounter global counter for true rms calculation
// length of delayLineArray - mult. inverse can be u

float trueRMS(float rtInput, float *delayLineArray, uint16_t delayLineCounter, uint16_t arrayLength){

	uint16_t i=0;
	float rms = 0.0f, rms_sum = 0.0f, rms_data=0.0f;

	*(delayLineArray+delayLineCounter) = rtInput;

	for (i = 0; i < arrayLength; i++)
	{

		rms_data=*delayLineArray ++;
		rms_sum+=rms_data*rms_data;
		
	}

	rms = sqrtf(rms_sum / arrayLength);

	return rms;

}

