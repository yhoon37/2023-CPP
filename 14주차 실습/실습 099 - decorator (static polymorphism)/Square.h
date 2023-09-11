#ifndef UNTITLED_SQUARE_H
#define UNTITLED_SQUARE_H
#include "Shape.h"

class Square : public Shape {
public:
    Square() = default;
    Square(int width, int height): width(width), height(height) {}
    ~Square() noexcept {};
    std::string toString() const override {
        std::ostringstream oss;
        oss << "Square has the width: " << width << ", height: " << height;
        return oss.str();
    };
    void setWidth(int width) { this->width = width; }
    void setHeight(int height) { this->height = height; }
private:
    int width=0, height=0;
};

#endif //UNTITLED_SQUARE_H
