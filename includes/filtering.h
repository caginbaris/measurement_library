
#ifndef __filtering_h
#define __filtering_h


#include <stdint.h>



typedef struct fof_coeffs{

	float b;
	float a;

}fof_coeffs;

float filtering(float rtInput,float *coeff, uint16_t coeffLength, float *zValues);
float lp_fo(float rtInput,float* xz,float yz,fof_coeffs coeff);
float hp_fo(float rtInput,float* xz,float yz,fof_coeffs coeff);

//macros

#define LP_FO(x,xz,y,coeffs)  y=lp_fo(x,&xz,y,coeffs)
#define HP_FO(x,xz,y,coeffs)  y=hp_fo(x,&xz,y,coeffs)

#endif

