#include "interpolation.h"
#include "sine_table.h"
#include <math.h>


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
float saw_generator(float input)
{
	return 1;
}


///////////////////////////////////////////////////////////////////////////////
// square_generator()
// 
float square_generator(float input)
{
	return 1;
}


///////////////////////////////////////////////////////////////////////////////
// triangle_generator()
// 
float triangle_generator(float input)
{
	return 1;
}