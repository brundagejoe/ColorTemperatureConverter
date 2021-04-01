import numpy as np

kelvinTemp = 1000

kelvinTemp = kelvinTemp / 100

def RestrictBounds(value):
    if value < 0:
        return 0
    if value > 255:
        return 255
    else:
        return value

def ConvertToDecimal(value):
    return value / 255

def CalculateRed(kelvinTemp):
    if kelvinTemp <= 66:
        return 255
    else:
        red = kelvinTemp - 60
        red = 329.698727446 * (red ** -0.1332047592)
        return RestrictBounds(red)

def RGBToHex(red, green, blue):
    rgb = (int(red), int(green), int(blue))
    return '%02x%02x%02x' % rgb

def CalculateGreen(kelvinTemp):
    if kelvinTemp <= 66:
        green = kelvinTemp
        green = 99.4708025861 * np.log(green) - 161.1195681661
        return RestrictBounds(green)
    else:
        green = kelvinTemp - 60
        green = 288.1221695283 * (green ** -0.0755148492)
        return RestrictBounds(green)

def CalculateBlue(kelvinTemp):
    if kelvinTemp >= 66:
        return 255
    else:
        if kelvinTemp <= 19:
            return 0
        else:
            blue = kelvinTemp - 10
            blue = 138.5177312231 * np.log(blue) - 305.0447927307
            return RestrictBounds(blue)

red = CalculateRed(kelvinTemp)
green = CalculateGreen(kelvinTemp)
blue = CalculateBlue(kelvinTemp)

red_decimal = ConvertToDecimal(red)
green_decimal = ConvertToDecimal(green)
blue_decimal = ConvertToDecimal(blue)

hexidecimal_value = RGBToHex(red, green, blue)

print("rgb (0-255) values are: ", red, ",", green, ",", blue)
print("rgb (0-1)   values are: ", red_decimal, ",", green, ",", blue)
print("Hexidecimal value is    ", hexidecimal_value)
