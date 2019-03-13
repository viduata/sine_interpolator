#include <math.h>

#include <stdio.h>
#include <stdlib.h>

// This program outputs a sine table at one-degree intervals
// The values are scaled to fit almost full-scale in the 16-bit space
// to accomodate a signed 16-bit output over i2s to an audio codec
//
// At the current time, it is implemented such that you run it and
// copy/paste the output code into sine_table.h
//
// Future versions will automatically create sine_table.h

int main (int argc, char * arg[])
{
	int x;
	float rads;
	float multiplier=32767;

	printf("float sine_table[] = {");
	for (x = 0; x<360; x++)
	{
		rads = x*3.14159/180.0;

		printf("%.2f", sin(rads)*multiplier);
		if((x+1)%5==0 && x!=0){printf(", \r\n");}
		else      {printf(", ");}

	}
	printf("};\r\n");

	return 0;
}