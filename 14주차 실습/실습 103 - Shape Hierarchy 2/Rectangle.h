#ifndef UNTITLED_RECTANGLE_H
#define UNTITLED_RECTANGLE_H
#include "IShape.h"
#include "Helper.h"
#include <iomanip>

class Rectangle : public IShape{
public:
    Rectangle(std::vector<Point> points):IShape(points){}
    ~Rectangle(){std::cout << "Rectangle destructor called" << std::endl;}
    double getArea() const override{
        double x = calcDist(points[1], points[2]);
        double y = calcDist(points[0], points[1]);

        return x*y;
    }
    double getPerimeter() const override{
        double len1 = calcDist(points[0], points[1]);
        double len2 = calcDist(points[1], points[2]);
        double len3 = calcDist(points[2], points[3]);
        double len4 = calcDist(points[3], points[0]);

        return len1 + len2 + len3 + len4;
    }
    std::string toString() const override{
        std::stringstream msg;
        msg << std::fixed << std::setprecision(2);
        msg << "Rectangle Area: " << getArea() << ", Perimeter: " << getPerimeter();
        return msg.str();
    }
private:

};
#endif //UNTITLED_RECTANGLE_H
