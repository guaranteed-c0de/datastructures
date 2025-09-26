#ifndef BASIC_SHAPE_H
#define BASIC_SHAPE_H
class BasicShape
{
    private:
        double area;
    
    public:
       double getArea()
       {return area;}
       virtual double calcArea() = 0;
};
#endif //BASIC_SHAPE_H