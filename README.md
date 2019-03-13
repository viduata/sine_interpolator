# wave_interpolator
A fast wave generator for microcontrollers.
Emphasis is on low RAM usage, and simple mathematics to allow real-time generation.

# Tools:
sine_interpolator:  fast sine wave interpolator for microcontrollers using wave table lookup
square_generator:   fast square wave generator
triangle_generator: fast triangle wave generator
sawtooth_generator: fast sawtooth generator

# Note
All tools are meant to generate a single output value that is determined procedurally
This gives the designer the ability to change frequencies in sine, and triangle without
any "jumps" in value which would create noise.
