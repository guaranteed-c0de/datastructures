#include <iostream>
#include "math_functions.h"

int main() {

    double num = 25.0;
    double result = compute_sqr_root(num);
    std:: cout << "square root of " << num << " is " << result << std::endl;
    return 0;
}