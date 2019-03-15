#ifndef WAVE_TYPES_H
#define WAVE_TYPES_H

// These are all full-scale types
#define SINE		1
#define SAWTOOTH	2
#define R_SAWTOOTH	3
#define TRIANGLE	4
#define SQUARE		5
#define UNIT_SINE	6

// Variable amplitude types
#define SCALED_SINE	7


typedef struct
{
	int   type;
	float position;
	float frequency;
	float interval;
	float amplitude;
} oscillator_t;


#endif