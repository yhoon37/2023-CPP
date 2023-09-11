#ifndef UNTITLED_CIRCLE_H
#define UNTITLED_CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
public:
    Circle() = default;
    Circle(int radius): radius(radius) {}
    ~Circle() noexcept {};
    std::string toString() const override {
        std::ostringstream oss;
        oss << "Circle has the radius: " << radius;
        return oss.str();
    };
    void setRadius(int radius) { this->radius = radius; }
private:
    int radius = 0;
};

#endif //UNTITLED_CIRCLE_H
