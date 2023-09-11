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
    int e1=0, e2=0;
    std::cin >> e1;
    std::cin >> e2;
    vec.erase(vec.begin()+e1);
    vec.erase(std::remove(vec.begin(), vec.end(), e2), vec.end());
    std::cout << vec.size() << std::endl;
    for(const int& v: vec)
        std::cout << v << " ";
    return 0;
}
