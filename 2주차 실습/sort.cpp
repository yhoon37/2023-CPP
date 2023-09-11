#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int size = 0;
    std::cin >> size;
    std::vector<int> vec(size);
    for(int i=0; i<size; i++){
//        int a=0;
//        std::cin >> a;            이렇게 하면 필요없는 0 값이 생기네?
//        vec.push_back(a);
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());

    for(const int& v: vec)
        std::cout << v << " ";
    return 0;
}
