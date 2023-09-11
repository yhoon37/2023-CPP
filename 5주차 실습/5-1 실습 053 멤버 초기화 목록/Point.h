#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H
#include <cmath>    //sqrt함수 사용을 위해

class Point {
public:
    Point(double x=0, double y=0) : x(x), y(y) {}
    double norm() const {return sqrt(x*x + y*y);};
    double getX() const {return x;}
    double getY() const {return y;}
private:
    const double x, y;
};

#endif //UNTITLED_POINT_H
