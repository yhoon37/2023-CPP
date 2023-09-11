#ifndef UNTITLED_MY_VECTOR_H
#define UNTITLED_MY_VECTOR_H

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <memory>
#include "my_vector_iterator.h"

template<typename T>
class my_vector {
public:
    // 실습 8-2 에서 정의한 my_vector의 멤버 함수들
    explicit my_vector(size_t N=0) noexcept {
        _size = N;
        _data = nullptr;
    }

    my_vector(std::initializer_list<int> lst) noexcept:_size(lst.size()), _data(new T[_size]){
        std::copy(lst.begin(), lst.end(), _data.get());
    }

    my_vector(const my_vector<T>& other) noexcept:_size(other.size()), _data(new T[_size]) {
        for(int i=0; i<_size; i++){
            _data.get()[i] = other._data.get()[i];
        }
    }

    T& operator[](int i) {
        return _data.get()[i];
    }

    size_t size() const {
        return _size;
    }
    // 추가 함수들 - begin(), end()
    my_vector_iterator<T> begin() {
        return my_vector_iterator<T>(_data.get());
    }

    my_vector_iterator<T> end() {
        return my_vector_iterator<T>(_data.get()+_size);
    }
private:
    size_t _size;
    std::unique_ptr<T[]> _data;
};

#endif //UNTITLED_MY_VECTOR_H
