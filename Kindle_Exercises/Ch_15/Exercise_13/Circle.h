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
    void setCenterX(long int x) {centerX = x;}
    void setCenterY(long int y) {centerY = y;}
   void calcArea() override {
   double a = 3.1415  * radius * radius;
    setArea(a);
}

}; //End of Circle class definition.
#endif //CIRCLE_H
