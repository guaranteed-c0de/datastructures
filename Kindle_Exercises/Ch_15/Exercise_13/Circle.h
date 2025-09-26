#include "BasicShape.h"
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
        calcArea(radius);
    }

    long int getCenterX() {return centerX;}
    long int getCenterY() {return centerY;}
    void calcArea(double);

};
