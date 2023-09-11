#include <iostream>
#include "Matrix.h"

using namespace std;

void print_matrix(string name, matrix m){
    cout << name << endl;
    cout << m << endl;
}

int main(){
    matrix m1 = {{4, 1}, {-7, -3}} ;
    matrix m2 = {{1, 1}, {0, 0}} ;

    matrix m3 (m1 + m2);
    matrix m4 = m3;

    print_matrix("m3", m3);
    print_matrix("m4", m4);
    print_matrix("m4.inverse", m4.inverse());

    matrix m5 = {{}};
    print_matrix("m5", m5);
    print_matrix("m5.inverse", m5.inverse());

    matrix m6(m5);
    print_matrix("m6", m6);
    print_matrix("m6.inverse", m6.inverse());

    matrix m7 = m4.inverse();
    m7 = m7 + matrix( {{0, 0}, {8, 6}});

    print_matrix("m4", m4);
    print_matrix("m4.inverse", m4.inverse());

    print_matrix("m7", m7);
    print_matrix("m7.inverse", m7.inverse());
}