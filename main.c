
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
	char * filename; 
	FILE * fh;
	float value = 0;
	int16_t intvalue = 0;
	float  wave_position = 0;

	printf("Starting interpolator\r\n");

	if(argc!=5)
	{
		printf("Usage: %s <freq> <duration> <sample rate> <outfile>\r\n", arg[0]);
		exit(1);
	}

	sample_rate = atof(arg[3]);
	frequency   = atof(arg[1]);
	duration    = atof(arg[2]);
	filename    = arg[4];

	fh = fopen(filename, "w");

	samples  = floor( sample_rate * duration );
	interval = 360/(sample_rate / frequency);

	for (x=0; x<samples; x++)
	{
		value = sine_interpolator(wave_position); // gives a sine wave
		intvalue = (int16_t)value;

		printf("%f, %f\r\n", x, value); 
		fwrite(&intvalue,sizeof(int16_t), 1, fh);
		wave_position += interval;

		// value = sine_interpolator(wave_position); // gives a sine wave
		// printf("%f, %f\r\n", x, saw_generator(x*interval)); // gives a square wave
		// printf("%f, %f\r\n", x, triangle_generator(x*interval)); // gives a triangle wave
	}

	frequency *= 1.5;
	interval = 360/(sample_rate / frequency);

	for (x=0; x<samples; x++)
	{
		value = sine_interpolator(wave_position);// gives a sine wave
		intvalue = (int16_t)value;
		printf("%f, %f\r\n", x, value); 
		fwrite(&intvalue,sizeof(int16_t), 1, fh);
		wave_position += interval;
	}

	frequency *= 1.5;
	interval = 360/(sample_rate / frequency);

	for (x=0; x<samples; x++)
	{
		value = sine_interpolator(wave_position);// gives a sine wave
		intvalue = (int16_t)value;
		printf("%f, %f\r\n", x, value); 
		fwrite(&intvalue,sizeof(int16_t), 1, fh);
		wave_position += interval;
	}

	fclose(fh);

	return 0;
}


