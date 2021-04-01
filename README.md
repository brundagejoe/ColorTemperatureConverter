# Color Temperature Converter

The Color Temperature Converter takes a color temperature in Kelvin and converts it to an RGB value (either 0-1 or 1-255)

## Purpose of Creation

Lighting by color temperature is a common convention in filmmaking, photography, and visual effects. However, some render engines only take RGB values as input (like *Mantra* or *Cycles*). In those circumstances, users will frequently try to estimate the correct color values on a blue-orange scale. This is **not** the correct approach. The math is more complicated, and as such, a complex algorithm should be used. Tanner Helland's algorithm, along with an explanation on how it was created, can be found [here](https://tannerhelland.com/2012/09/18/convert-temperature-rgb-algorithm-code.html). This program is simply a C++ and python implementation of the algorithm.

## Understanding Color Temperatures

![Color Temp Chart](https://user-images.githubusercontent.com/70725104/113328527-a3e22f00-92d9-11eb-9046-77a511dc1521.jpeg)

Color temperatures are measured in Kelvin. The lower temperatures appear more orange and higher temperatures appear more blue. However, it's important to note that Helland's algorithm "is only designed to be used between 1000 K and 40000 K, which is a nice spectrum for photography... While it will work for temperatures outside these ranges, estimation quality will decline."

## Python vs C++

I first ported the algorithm to C++ for quick use on linux machines, but have since ported it to Python in a modular form. Therefore, the python code could easily be applied into software such as *Maya*, *Houdini*, or *Blender*.

#### A few notes on the Python Code
The rgb values are each calculated separately in three distinct functions:
```python
def CalculateRed(kelvinTemp)
def CalculateBlue(kelvinTemp)
def CalculateGreen(kelvinTemp)
```

It is also worth noting that `RestrictBounds(value)` is just a helper function for those mentioned above, while `ConvertToDecimal(value)` converts an RGB value of 0-255 to 0-1. 

Users might find the RGBToHex function especially useful when implementing the code in other software:
```python
def RGBToHex(red, green, blue):
    rgb = (int(red), int(green), int(blue))
    return '%02x%02x%02x' % rgb
```

But it should be noted that the 0-255 values should be entered, **not** 0-1.
