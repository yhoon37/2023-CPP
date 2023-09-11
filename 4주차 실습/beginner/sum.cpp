#include <iostream>
#include <vector>

extern std::vector<int> vec;
extern int total;

void sum(void){
    for(auto & it : vec){
        total += it;
    }
}