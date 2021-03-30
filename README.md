# Color Temperature Converter

The Color Temperature Converter takes a color temperature in Kelvin and converts it to an RGB value (either 0-1 or 1-255)

## Purpose of Creation

Lighting by color temperature is a common convention in filmmaking, photography, and visual effects. However, some render engines only take RGB values as input (like *Mantra* or *Cycles*). In those circumstances, users will frequently try to estimate the correct color values on a blue-orange scale. This is **not** the correct approach. The math is more complicated, and as such, a complex algorithm should be used. Tanner Helland's algorithm, along with an explanation on how it was created, can be found [here](https://tannerhelland.com/2012/09/18/convert-temperature-rgb-algorithm-code.html). This program is simply a C++ implementation of the algorithm.
