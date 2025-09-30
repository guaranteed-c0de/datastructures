#include "BasicShape.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle: public BasicShape { //This describes public inheritance, which means that any Rectangle object can be treated with an "is-a" relationship of the base class BasicShape.
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
        void calcArea() override { //The function is overridden here because the base class is a pure abstract base class.
            double a = length * width; //Yes, it is better to have a defined as data type here instead of writing setArea(length * width).
            setArea(a); //While I don't prefer to do it, here is calling a function within another function.
    } //To override the function is to redefine it from the base class. Functions need not always be overridden, but they might, depending on the derived class.
        long int getWidth()
        {return width;}
        long int getLength()
        {return length;} 
}; //End of Rectangle class definition.
#endif //RECTANGLE_H