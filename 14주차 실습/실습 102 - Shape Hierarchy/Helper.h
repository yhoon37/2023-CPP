#ifndef UNTITLED_HELPER_H
#define UNTITLED_HELPER_H
#include "IShape.h"
#include <cmath>

double calcDist(const Point& p1, const Point& p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return std::sqrt(dx*dx + dy*dy);
}

#endif //UNTITLED_HELPER_H
