
#ifndef UNTITLED_COMPLEX_H
#define UNTITLED_COMPLEX_H
#include <array>
#include <iostream>
using namespace std;

class Complex{
public:
    Complex(int r, int i): r(r), i(i){}
    bool operator == (Complex& other){
        if((r == other.r)&&(i == other.i)){
            return true;
        }
        return false;
    }
    friend ostream& operator << (ostream& os, Complex& c);
private:
    int r;
    int i;
};

ostream& operator << (ostream& os, Complex& c){
    os << c.r << " + " << c.i << "i" << endl;
}

template <typename T, size_t N>
auto myFind(std::array<T, N>& arr, T target) {
    auto result = begin(arr);
    while(result != end(arr)){
        if(target == *result) break;
        result ++;
    }
    return result;
}

#endif //UNTITLED_COMPLEX_H
