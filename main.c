
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "settings.h"
#include "wave_types.h"
#include "interpolation.h"



// FUNCTION PROTOTYPES
void wave_init(oscillator_t * the_wave, int wave_type, float wave_freq, float wave_amp );
void wave_increment(oscillator_t * the_wave);
void wave_recalculate(oscillator_t * the_wave);

// GLOBAL VARIABLES
oscillator_t principle_wave;
oscillator_t lf_modulator;

int main (int argc, char * arg[])
{
	char * 	filename; 
	filename = arg[1];
	FILE * fh;
	int 	samples = SAMPLE_RATE * 5; // Create five seconds of audio
	float 	root_frequency = 440;
	float 	mod_frequency  = 440;
	float 	lfo_frequency  = 40;
	float 	lfo_depth      = 40;
	int 	intvalue       = 0;
	float 	value          = 0;
	long    x			   = 0;

	wave_init (&principle_wave, root_frequency, 440, 0); 	// Principle sine wave at 440 Hz
	wave_init (&lf_modulator, UNIT_SINE, lfo_frequency, 0); // LFO FM oscillator at 2 Hz

	// Open file for writing
	fh = fopen(filename, "w");

	// Everything happens in one loop
	for (x=0; x<samples; x++)
	{
		value = sine_interpolator(principle_wave.position);
		intvalue = (int16_t)value;
		principle_wave.frequency = root_frequency + (unit_sine(lf_modulator.position)*lfo_depth);
		wave_recalculate(&principle_wave);
		wave_increment(&principle_wave);
		wave_increment(&lf_modulator);

		printf("%ld, %f\r\n", x, value); 
		fwrite(&intvalue,sizeof(int16_t), 1, fh);

		// value = sine_interpolator(wave_position); // gives a sine wave
		// intvalue = (int16_t)value;

		// printf("%f, %f\r\n", x, value); 
		// fwrite(&intvalue,sizeof(int16_t), 1, fh);
		// wave_position += interval;

		// value = sine_interpolator(wave_position); // gives a sine wave
		// printf("%f, %f\r\n", x, saw_generator(x*interval)); // gives a square wave
		// printf("%f, %f\r\n", x, triangle_generator(x*interval)); // gives a triangle wave
	}

	// frequency *= 1.5;
	// interval = 360/(sample_rate / frequency);

	// for (x=0; x<samples; x++)
	// {
	// 	value = sine_interpolator(wave_position);// gives a sine wave
	// 	intvalue = (int16_t)value;
	// 	printf("%f, %f\r\n", x, value); 
	// 	fwrite(&intvalue,sizeof(int16_t), 1, fh);
	// 	wave_position += interval;
	// }

	// frequency *= 1.5;
	// interval = 360/(sample_rate / frequency);

	// for (x=0; x<samples; x++)
	// {
	// 	value = sine_interpolator(wave_position);// gives a sine wave
	// 	intvalue = (int16_t)value;
	// 	printf("%f, %f\r\n", x, value); 
	// 	fwrite(&intvalue,sizeof(int16_t), 1, fh);
	// 	wave_position += interval;
	// }

	fclose(fh);

	return 0;
}



void wave_init(oscillator_t * the_wave, int wave_type, float wave_freq, float wave_amp )
{
	the_wave -> type = wave_type;		// sine, tri, etc.
	the_wave -> position = 0;			// start at zero. change manually if required
	the_wave -> frequency = wave_freq; 	// frequency in hz
	the_wave -> interval = 360/(SAMPLE_RATE / the_wave -> frequency);	// Calculated interval
	the_wave -> amplitude = wave_amp;	// Only needed for scaled types.
}

void wave_recalculate(oscillator_t * the_wave)
{
	the_wave -> interval = 360/(SAMPLE_RATE / the_wave -> frequency);
}

void wave_increment(oscillator_t * the_wave)
{
	the_wave -> position += the_wave -> interval;
	the_wave -> position = fmod(the_wave-> position, 360);
}


	// float x=0;
	// float duration;
	// float sample_rate;
	// float frequency;
	// int   samples;
	// float interval;

	// FILE * fh;
	// float value = 0;
	// int16_t intvalue = 0;
	// float  wave_position = 0;

	// printf("Starting interpolator\r\n");

	// if(argc!=5)
	// {
	// 	printf("Usage: %s <freq> <duration> <sample rate> <outfile>\r\n", arg[0]);
	// 	exit(1);
	// }

	// sample_rate = atof(arg[3]);
	// frequency   = atof(arg[1]);
	// duration    = atof(arg[2]);

	// samples  = floor( sample_rate * duration );
	// interval = 360/(sample_rate / frequency);