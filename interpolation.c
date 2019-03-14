#include "interpolation.h"
#include "sine_table.h"
#include <math.h>

const float saw_factor = 65534/360;
const float tri_factor = 65534/180;
const float unit_tri_factor = 1/180;

///////////////////////////////////////////////////////////////////////////////
// sine_interpolator()
// Given a value (in degrees), this uses a pre-baked table of sine values
// to give an approximation of sine.
// The method used is a simple first-order linear approximation
float sine_interpolator(float input)
{
	int left = floor(input);
	left = left % 360;

	input = fmod(input, 360);

	return (input*sine_table[(left+1)%360] - input*sine_table[left] + sine_table[left]*(left+1) - (left*sine_table[(left+1)%360]));
}


///////////////////////////////////////////////////////////////////////////////
// saw_generator()
// 
// generates a rising sawtooth between 32767 and -32767
float saw_generator(float input)
{

	float saw_input = fmod(input, 360);
	
	return saw_factor*saw_input - 32767;
}

///////////////////////////////////////////////////////////////////////////////
// reverse_saw_generator()
// 
// generates a falling sawtooth between 32767 and -32767
float reverse_saw_generator(float input)
{
	float saw_input = fmod(input, 360);
	
	return 32767 - saw_factor*saw_input;
}

///////////////////////////////////////////////////////////////////////////////
// triangle_generator()
// 
// generates a fast sawtooth between 32767 and -32767
float triangle_generator(float input)
{
	float tri_input = fmod(input, 360);
	if(tri_input<180)
	{
		return (tri_factor * tri_input) - 32767;
	}
	else
	{
		return 32767 - (tri_factor * (tri_input-180)) ;
	}
}

///////////////////////////////////////////////////////////////////////////////
// square_generator()
// 
// generates a square wave between 32767 and -32767
float square_generator(float input)
{
	float tri_input = fmod(input, 360);
	if(tri_input<180)
	{
		return - 32767;
	}
	else
	{
		return 32767;
	}
}


///////////////////////////////////////////////////////////////////////////////
// unit_triangle()
// 
// generates a positive triangle wave from 0 to 1 and back
float unit_triangle(float input)
{
	float tri_input = fmod(input, 360);
	if(tri_input<180)
	{
		return (unit_tri_factor * tri_input);
	}
	else
	{
		return 1 - (unit_tri_factor * (tri_input-180)) ;
	}
}

