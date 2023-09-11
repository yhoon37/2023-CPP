#ifndef UNTITLED_TRIANGLE_H
#define UNTITLED_TRIANGLE_H
#include "IShape.h"
#include "Helper.h"
#include <iomanip>

class Triangle : public IShape{
public:
    Triangle(std::vector<Point> points):IShape(points){}
    ~Triangle(){std::cout << "Triangle destructor called" << std::endl;}
    double getArea() const override{
        double x = calcDist(points[1], points[2]);
        double y = calcDist(points[0], points[1]);
        return x*y/2;
    }
    double getPerimeter() const override{
        double len1 = calcDist(points[0], points[1]);
        double len2 = calcDist(points[1], points[2]);
        double len3 = calcDist(points[2], points[0]);

        return len1 + len2 + len3;
    }
    std::string toString() const override{
        std::stringstream msg;
        msg << std::fixed << std::setprecision(2);
        msg << "Triangle Area: " << getArea() << ", Perimeter: " << getPerimeter();
        return msg.str();
    }
private:

};
#endif //UNTITLED_TRIANGLE_H
