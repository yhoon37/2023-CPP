#ifndef UNTITLED_POLYGON_H
#define UNTITLED_POLYGON_H
#include "IShape.h"
#include "Helper.h"
#include <iomanip>

class Polygon : public IShape{
public:
    Polygon(std::vector<Point> points):IShape(points){}
    ~Polygon(){std::cout << "Polygon destructor called" << std::endl;}
    double getArea() const override{
        double x = calcDist(points[1], points[2]);
        double y = calcDist(points[0], points[1]);
        double y2 = points[4].y - points[0].y;
        return x * y - x*y2/2;
    }
    double getPerimeter() const override{
        double len1 = calcDist(points[0], points[1]);
        double len2 = calcDist(points[1], points[2]);
        double len3 = calcDist(points[2], points[3]);
        double len4 = calcDist(points[3], points[4]);
        double len5 = calcDist(points[4], points[0]);

        return len1 + len2 + len3 + len4 + len5;
    }
    std::string toString() const override{
        std::stringstream msg;
        msg << std::fixed << std::setprecision(2);
        msg << "Polygon Area: " << getArea() << ", Perimeter: " << getPerimeter();
        return msg.str();
    }
private:

};


#endif //UNTITLED_POLYGON_H
