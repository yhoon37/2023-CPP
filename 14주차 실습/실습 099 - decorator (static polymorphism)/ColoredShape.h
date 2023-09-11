#ifndef UNTITLED_COLOREDSHAPE_H
#define UNTITLED_COLOREDSHAPE_H
#include <sstream>
#include "Shape.h"

template <typename T>
class ColoredShape : public T {
public:
    ColoredShape() = default;
    ~ColoredShape() noexcept {}
    // your code here
    ColoredShape(Color color): color(color){}
    std::string toString() const override {
        std::ostringstream oss;
        oss << T::toString() << ", color: " << color;
        return oss.str();
    };
    template<typename... Args>
    ColoredShape(Color color, Args... args) : color(color), T(std::forward<Args>(args)...){}
private:
    Color color=RED;
};

#endif //UNTITLED_COLOREDSHAPE_H
