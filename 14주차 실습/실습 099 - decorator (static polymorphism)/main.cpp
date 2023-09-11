#include <iostream>
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "ColoredShape.h"
#include "TransparentShape.h"


int main() {
    ColoredShape<TransparentShape<Square>> square{RED};
    square.setWidth(10);
    square.setHeight(10);
    std::cout << square.toString() << std::endl;

    TransparentShape<ColoredShape<Circle>> circle{70};
    circle.setRadius(5);
    std::cout << circle.toString() << std::endl;

    TransparentShape<ColoredShape<Circle>> red_circle{100, RED};
    red_circle.setRadius(7);
    std::cout << red_circle.toString() << std::endl;

    return 0;
}