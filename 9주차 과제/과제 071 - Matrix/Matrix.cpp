#include "Matrix.h"
//제출할때는 주석처리한 for문 지우기
matrix::matrix(initializer_list<int> r1, initializer_list<int> r2) {
    col = r1.size();
    row = !!r1.size() + !!r2.size();
    data = new int[r1.size() + r2.size()];

//    for(int i=0; i<r1.size(); i++) data[i] = *(r1.begin()+i);
//    for(int i=0; i<r2.size(); i++) data[i+r1.size()] = *(r2.begin()+i);
    copy(r1.begin(), r1.end(),data);
    copy(r2.begin(), r2.end(), data+col);
}

matrix::matrix(int *newData, size_t row, size_t col):data(new int[row*col]), row(row), col(col) {
    //for(int i=0; i<row*col; i++) data[i] = newData[i];
    copy(newData, newData+row*col, data);
}

matrix::matrix(const matrix& m){
    if(this != &m){
        col = m.col;
        row = m.row;
        data = new int[col * row];
//        for(int i=0; i<col*row; i++) data[i] = m.data[i];
        copy(m.data, m.data+row*col, data);
    }
}

matrix matrix::operator=(const matrix& m){
    if(this == &m) return *this;
    else{
        col = m.col;
        row = m.row;
        data = new int[col * row];
        copy(m.data, m.data+row*col, data);
        return *this;
    }
}

matrix matrix::operator+(const matrix &m) {
    if(row == m.row && col == m.col){
        int newData[row*col];
        for(int i=0; i<row*col; i++) newData[i] = data[i] + m.data[i];
        return matrix{newData, row, col};
    }
}

matrix::~matrix(){delete[] data;}

matrix matrix::inverse(){
    if(row==2 && col==2){
        int newData[4];
        newData[0] = -data[3];
        newData[1] = data[1];
        newData[2] = data[2];
        newData[3] = -data[0];
        return matrix(newData, row, col);
    }
    else if(row==1 && col==1){
        int newData[1];
        newData[0] = 1/data[0];
        return matrix(newData, row, col);
    }
    return *this;
}

ostream& operator << (ostream& os, matrix& m){
    if(m.row != 0){
        for(int i=0; i<m.row; i++){
            os << "| ";
            for(int j=0; j<m.col; j++) os << m.data[i*m.col+j] << " ";
            os <<"|" << endl;
        }
    }
    else{
        os << "| |" << endl;
    }
    return os;
}