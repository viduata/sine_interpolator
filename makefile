normal: main.c interpolation.c
	gcc main.c interpolation.c -lm -o interpolator

all: main.c interpolation.c table_maker.c
	gcc main.c interpolation.c -lm -o interpolator
	gcc table_maker.c -lm -o table_maker
	