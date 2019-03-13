#include "interpolation.h"
#include "sine_table.h"
#include <math.h>

float sine_interpolator(float input)
{
	int left = floor(input);
	left = left % 360;

	input = fmod(input, 360);

	return (input*sine_table[(left+1)%360] - input*sine_table[left] + sine_table[left]*(left+1) - (left*sine_table[(left+1)%360]));
}