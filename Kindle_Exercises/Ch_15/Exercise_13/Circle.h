#include "BasicShape.h"
#ifndef CIRCLE_H
#define CIRCLE_H
class Circle: public BasicShape {
private:
    long int centerX;
    long int centerY;
    double radius;
public:
    Circle (long int x, long int y, double r)
    {
        centerX = x;
        centerY = y;
        radius = r;
        calcArea();
    }

    long int getCenterX() {return centerX;}
    long int getCenterY() {return centerY;}
   double calcArea() override {
    return 3.1415 * radius * radius;
}

};
#endif //CIRCLE_H
