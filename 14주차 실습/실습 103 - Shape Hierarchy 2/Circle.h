#ifndef UNTITLED_CIRCLE_H
#define UNTITLED_CIRCLE_H
#include "IShape.h"
#include <cmath>
#include <sstream>
#include <iomanip>

class Circle: public IShape{
public:
    Circle(Point center, int r): IShape(), center(center), radius(r){}
    ~Circle() noexcept{std::cout << "Circle destructor called" << std::endl;}
    double getArea() const override{
        return radius * radius * M_PI;
    }
    double getPerimeter() const override{
        return 2 * M_PI * radius;
    }
    std::string toString() const override{
        std::stringstream msg;
        msg << std::fixed << std::setprecision(2);
        msg << "Circle Area: " << getArea() << ", Perimeter: " << getPerimeter();
        return msg.str();
    }
private:
    Point center;
    int radius;
};

#endif //UNTITLED_CIRCLE_H
