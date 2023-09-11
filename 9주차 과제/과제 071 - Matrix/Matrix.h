#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <iostream>
#include <initializer_list>
#include <algorithm>
using namespace std;

class matrix {
public:
    // 생성자, 복사생성자
    // 연산자 오버로딩
    // 멤버 함수들
    matrix(initializer_list<int> r1={}, initializer_list<int> r2={});
    matrix(int* data, size_t row, size_t col);
    matrix(const matrix& m);
    matrix operator = (const matrix& m);
    matrix operator + (const matrix& m);
    ~matrix();

    matrix inverse();
    friend ostream& operator << (ostream& os, matrix& m);

private:
    int* data = nullptr;
    size_t row = 0;
    size_t col = 0;
};

#endif //MATRIX_MATRIX_H
