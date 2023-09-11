#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int num, size=0;
    std::vector<int> vec;
    while(std::cin >> num){
        size++;
        vec.push_back(num);
    }
    auto min = std::min_element(begin(vec), end(vec));
    auto max = std::max_element(begin(vec), end(vec));
    std::cout << size << " " << *min << " " << *max;
}
