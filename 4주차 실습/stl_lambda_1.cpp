#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


int main(){
    int N, X;
    std::cin >> N >> X;
    std::vector<int> vec;

    std::generate_n(std::back_inserter(vec), N, [] () {return *(std::istream_iterator<int>{std::cin}); });
    copy_if (vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "), [=](int x){return X > x;});
}
