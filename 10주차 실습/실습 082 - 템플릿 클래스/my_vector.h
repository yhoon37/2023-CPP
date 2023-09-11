#ifndef UNTITLED_MY_VECTOR_H
#define UNTITLED_MY_VECTOR_H

#include <algorithm>
#include <initializer_list>
#include <memory>

template<typename T>
class my_vector {
public:
    explicit my_vector(size_t N=0) noexcept {
        _size = N;
        _data = nullptr;
    }

    my_vector(std::initializer_list<T> lst) noexcept:_size(lst.size()), _data(new T[_size]){
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

private:
    size_t _size;
    std::unique_ptr<T[]> _data;
};

#endif //UNTITLED_MY_VECTOR_H
