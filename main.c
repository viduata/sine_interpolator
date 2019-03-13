
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sine_table.h"


// sine lookups come from the sine_table.h file
// in a float array called sine_table


// FUNCTION PROTOTYPES
float get_interpolated_value(float input);


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
		printf("%f, %f\r\n", x, get_interpolated_value(x*interval));
	}



	// for (x=0; x<720; x+=3.625)
	// {
	// 	printf("%f, %f\r\n", x, get_interpolated_value(x));
	// }
	return 0;
}


float get_interpolated_value(float input)
{
	int left = floor(input);
	left = left % 360;

	input = fmod(input, 360);

	return (input*sine_table[(left+1)%360] - input*sine_table[left] + sine_table[left]*(left+1) - (left*sine_table[(left+1)%360]));
}