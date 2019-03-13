
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "interpolation.h"


// sine lookups come from the sine_table.h file
// in a float array called sine_table


// FUNCTION PROTOTYPES



int main (int argc, char * arg[])
{
	float x=0;
	float duration;
	float sample_rate;
	float frequency;
	int   samples;
	float interval;

	printf("Starting interpolator\r\n");

	if(argc!=4)
	{
		printf("Usage: %s <freq> <duration> <sample rate>\r\n", arg[0]);
		exit(1);
	}
	
	sample_rate = atof(arg[3]);
	frequency   = atof(arg[1]);
	duration    = atof(arg[2]);

	samples  = floor( sample_rate * duration );
	interval = 360/(sample_rate / frequency);

	for (x=0; x<samples; x++)
	{
		printf("%f, %f\r\n", x, sine_interpolator(x*interval));
	}

	return 0;
}


