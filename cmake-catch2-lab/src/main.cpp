#include <iostream> //#include <iomanip> is used in order to include functions and manipulators like setw(), setprecision(), and fixed.
#include "math_functions.h" //main.cpp must include math_functions.h because it will eventually use the function compute_sqr_root(). The compiler will check the function to ensure it matches what math_functions.h dictates.

int main() {

    double num = 25.0; 
    double result = compute_sqr_root(num); //This line calls for compute_sqr_root(), which is defined in math_functions.cpp, but is validated in math_functions.h
    std:: cout << "square root of " << num << " is " << result << std::endl;
    return 0;
}  //End of main.cpp
