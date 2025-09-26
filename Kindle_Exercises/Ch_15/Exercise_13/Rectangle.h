#include "BasicShape.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle: public BasicShape {
private:
    long int width;
    long int length;

public:
    Rectangle(long int w, long int l) //This is the constructor for class Rectangle.
    {
        width = w;
        length = l;
        calcArea(); //This is a function call for calcArea(). 
        } 
        double calcArea() override { //The function is overridden here because the base class is a pure abstract base class.
            return length * width; //But area is never defined as a value.
    }
        long int getWidth()
        {return width;}
        long int getLength()
        {return length;} 
}; //End of Rectangle class definition.
#endif //RECTANGLE_H