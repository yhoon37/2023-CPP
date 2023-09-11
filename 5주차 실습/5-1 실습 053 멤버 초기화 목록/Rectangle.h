#ifndef UNTITLED_RECTANGLE_H
#define UNTITLED_RECTANGLE_H
#include "Point.h"

class Rectangle {
public:
                                                                //{} 를 써도 되고 ()를 써도 되나??
    Rectangle(double x1, double y1, double x2, double y2) : leftTop{x1,y1}, rightBottom(x2,y2){}
    double area() {
        double width = abs(rightBottom.getX() - leftTop.getX());
        double height = abs(rightBottom.getY() - leftTop.getY());
        return width * height;
    };
private:
    Point leftTop, rightBottom;
};

#endif //UNTITLED_RECTANGLE_H
