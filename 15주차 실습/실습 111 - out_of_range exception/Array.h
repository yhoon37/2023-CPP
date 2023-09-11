#ifndef UNTITLED_ARRAY_H
#define UNTITLED_ARRAY_H
#include <iostream>
#include <cstddef>
#include <exception>
#include <string>

template<typename T>
class Array {
public:
    Array(size_t size) : size(size), data(new T[size]) {}
    T& at(size_t index){
        if (0<= index && index < size)
            return data[index];
        throw std::out_of_range(std::to_string(index));
    }
    ~Array() {delete[] data;}
private:
    T* data;
    size_t size;
};

#endif //UNTITLED_ARRAY_H
