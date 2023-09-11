#include <iostream>
#include "Array.h"

int main() {
    Array<int> arr(5);
    try {
        arr.at(0) = 1;
        arr.at(1) = 2;
        arr.at(2) = 3;
        arr.at(3) = 4;
        arr.at(4) = 5;
        arr.at(5) = 6;
    } catch(std::out_of_range& e){
        std::cerr << "Out of Range error: " << e.what() << '\n';
    }
    return 0;
}