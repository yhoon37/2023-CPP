#include <iostream>
#include <vector>
extern std::vector<int> vec;

void read(void){
    int size;
    std::cin >> size;
    for(int i=0; i<size; i++){
        int num;
        std::cin >> num;
        vec.push_back(num);
    }
}