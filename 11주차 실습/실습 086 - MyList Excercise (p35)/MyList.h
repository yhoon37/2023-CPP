#ifndef UNTITLED_MYLIST_H
#define UNTITLED_MYLIST_H
#include <iostream>
#include <complex>
#include <vector>
#include <algorithm> //또는 템플릿 함수로 구현
#include <cstddef>

template<typename T, size_t N>
class MyList {
public:
    MyList():_data(new T[N]){}
    MyList(const MyList& rhs) noexcept: _data(new T[N]){
        while(pos != rhs.pos){
            _data[pos] = rhs._data[pos];
            pos++;
        }
    }
    MyList& operator=(const MyList& rhs){
        _data = new T[N];
        while(pos != rhs.pos){
            _data[pos] = rhs._data[pos];
            pos++;
        }
        return *this;
    }
    ~MyList() noexcept{
        delete[] _data;
    }

    void add(T& data){
        _data[pos++] = data;
    }
    void remove(T& data){
        for(int i=0; i<pos; i++){
            if(_data[i] == data){
                for(int j=i; j<pos; j++){
                    _data[j] = _data[j+1];
                }
                T last;
                pos--;
                _data[pos] = last;
                break;
            }
        }
    }

    const T* begin() const {return _data;}
    const T* end() const {return _data + N;}

    T* begin() {return _data;}
    T* end() {return _data + N;}

private:
    T* _data= nullptr;
    int pos = 0;
};

//template <typename T, size_t N>
//auto myFind(MyList<T, N>& arr, T target) {
//    auto result = begin(arr);
//    while(result != end(arr)){
//        if(target == *result) break;
//        result ++;
//    }
//    return result;
//}

#endif //UNTITLED_MYLIST_H
