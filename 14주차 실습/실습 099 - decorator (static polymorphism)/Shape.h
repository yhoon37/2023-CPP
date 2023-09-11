#ifndef UNTITLED_SHAPE_H
#define UNTITLED_SHAPE_H
#include <string>

enum Color {RED, BLUE, GREEN};
class Shape {
public:
    virtual std::string toString() const = 0;
    virtual ~Shape() noexcept {};
};

#endif //UNTITLED_SHAPE_H
//가변 마이 리스트, 101,102,103 , 95?94?동적 다형성 내용으로
//3번째 문제는 prototype 섞음