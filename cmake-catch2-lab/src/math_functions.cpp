#include "math_functions.h"
#include <cmath> //Including the <cmath> header file allows access to multiple mathematical functions, like square roots, exponents, and the trigonometric functions like sin() and cos().
#include <stdexcept>
double compute_sqr_root(double number) { //All this file does is define the functions that will be used in main.cpp. We don't use int main{} because there is no code to 'execute'. Here, there is only code that will be summoned to complete a task.

    if (number < 0) { //I suppose it wouldn't be detrimental to do this the other way, but listing the condition 'if (number < 0)' is first, we can deal with the faultier conditions first. 
           throw std::runtime_error("This program only outputs real values. This number has no real square root value.");
    }
    return std:: sqrt(number);
} //End of math_functions.h
