#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void KelvinTempCalc();
int main() {
    cout << endl;
    cout << "Kelvin Color Temperature Calculator" << endl << endl;
    cout << "Enter the temperature in Kelvin, and it will output the RGB values. Type 'quit' at the end of the calculations to quit, or type anything else to calculate another value:" << endl << endl;
    std::string userInput;
    while (userInput != "quit") {
        KelvinTempCalc();
        cin >> userInput;
    }
    return 0;
}

void KelvinTempCalc() {
    int kelvinTemp;
    double red;
    double green;
    double blue;

    cout << "Enter Color Temperature in Kelvin: ";
    cin >> kelvinTemp;

    kelvinTemp = kelvinTemp /100;

    //Calculate Red
    if (kelvinTemp <= 66) {
      red = 255;
    }
    else {
      red = kelvinTemp - 60;
      red = 329.698727446 * pow(red, -0.1332047592);
      if (red < 0) {
        red = 0;
      }
      if (red > 255) {
        red = 255;
      }
    }

    //Calculate Green
    if (kelvinTemp <= 66) {
      green = kelvinTemp;
      green = 99.4708025861 * log(green) - 161.1195681661;
      if (green < 0) {
        green = 0;
      }
      if (green > 255) {
        green = 255;
      }
    }
    else {
      green = kelvinTemp - 60;
      green = 288.1221695283 * pow(green, -0.0755148492);
      if (green < 0) {
        green = 0;
      }
      if (green > 255) {
        green = 255;
      }
    }

    //Calculate blue
    if (kelvinTemp >= 66) {
      blue = 255;
    }
    else {
      if (kelvinTemp <= 19) {
        blue = 0;
      }
      else {
        blue = kelvinTemp - 10;
        blue = 138.5177312231 * log(blue) - 305.0447927307;
        if (blue < 0) {
          blue = 0;
        }
        if (blue > 255) {
          blue = 255;
        }
      }
    }

    cout << "RGB values are: " << red << "," << green << "," << blue << endl;
    red = red/255;
    green = green/255;
    blue = blue/255;

    cout << "In 0-1 range they are: " << red << "," << green << "," << blue << " ";
}
