#ifndef UNTITLED_TRANSPARENTSHAPE_H
#define UNTITLED_TRANSPARENTSHAPE_H
#include <sstream>
#include "Shape.h"

template <typename T>
class TransparentShape : public T {
public:
    TransparentShape()=default;
    ~TransparentShape() noexcept {}
    // your code here
    TransparentShape(int transparent): transparent(transparent){}
    std::string toString() const override {
        std::ostringstream oss;
        oss << T::toString() << ", transparent: " << transparent;
        return oss.str();
    };
    template<typename...Args>
    TransparentShape(int transparent, Args...args) : transparent(transparent), T(std::forward<Args>(args)...){}
private:
    int transparent=100;
};

#endif //UNTITLED_TRANSPARENTSHAPE_H
