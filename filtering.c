
#include "mlib.h"


float filtering(float rtInput,float *coeff, uint16_t coeffLength, float *zValues){

	uint16_t i;
  float *z1_ptr,*z2_ptr,*coeff_ptr;
  float output;

	z1_ptr=zValues; 		//background data
	z2_ptr=z1_ptr; 		//data update
	coeff_ptr=coeff+coeffLength-1;  //last element


	output=(*z1_ptr++) *(*coeff_ptr--);

	for(i=2;i<coeffLength;i++){
	
	*z2_ptr++ =*z1_ptr;
	output+=(*z1_ptr++) *(*coeff_ptr--);

	}


	output+=rtInput *(*coeff_ptr);
	*z2_ptr=rtInput;

	return(output);

}

float lp_fo(float rtInput,float* xz,float yz,fof_coeffs coeff)
{
	float y;
	
	y=coeff.b*(rtInput+(*xz))-coeff.a*(yz);
		
	(*xz)=rtInput;
	
	return y;
	
};


float hp_fo(float rtInput,float* xz,float yz,fof_coeffs coeff)
{
	float y;
	
	y=coeff.b*(rtInput-(*xz))-coeff.a*(yz);
		
	(*xz)=rtInput;
	
	return y;
	
};





