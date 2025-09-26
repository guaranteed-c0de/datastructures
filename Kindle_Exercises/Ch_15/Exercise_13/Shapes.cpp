#include "Rectangle.h"
#include "Circle.h"
#include <iostream>
using namespace std;
int main() {
Circle our_circle(2, 5, 8); 
Rectangle our_rectangle(3, 4); //our_rectangle is the name of a Rectangle object.
Circle* their = new Circle(2, 4, 6);
Rectangle *other = new Rectangle(4, 5); //These pointers are for objects that are created using dynamic memory allocation.

cout << "The area of the first circle is " << our_circle.calcArea() << endl;
cout << "The area of the first rectangle is " << our_rectangle.calcArea() << endl; //Recognize that this is calcArea(), not getArea(). Really, getArea() is redundant because calcArea() changes the value and returns it to where it was called. When I used getArea(), the program returned random values.
cout << "The area of the second circle is " << their -> calcArea() << endl; //their is a pointer that points to an object created on the heap.
cout << "The area of the second rectangle is" << other -> calcArea() << endl; //other is a pointer that points to the object that has certain properties defined upon the heap. other -> calcArea() means start from the pointer that has to the address, go to the object, and at that object, call the calcArea() function.
return 0;
} //End of Shapes.cpp
