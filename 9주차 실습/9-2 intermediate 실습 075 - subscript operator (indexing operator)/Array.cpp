#include "Array.h"

Array::Array(std::initializer_list<int> args, size_t size): _size(size), data(new int[size]){
    int i=0;
    for(auto num: args){
        data[i] = num;
        i++;
    }
}

 int& Array::operator [] (int index){
    if(index < _size) return data[index];
}

size_t Array::size() const{
    return _size;
}
//delete std::move []  new  int& std::unique_ptr<int[]>