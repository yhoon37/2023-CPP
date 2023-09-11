#include <iostream>

template<typename T>
T sum(T t){return t;}

template<typename T, typename... Args>
int sum(T arg0, Args... args){
    return arg0 + sum(args...);
}

int main() {
    std::cout<<sum(1, 2, 3, 4) <<std::endl;
    return 0;
}