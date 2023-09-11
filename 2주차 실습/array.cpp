#include <iostream>
#include <array>
#include <algorithm>

int main() {
   std::array<int, 10> arr;
   for(auto &iter:arr)
       std::cin >> iter;
   auto min = std::min_element(begin(arr), end(arr));
   auto max = std::max_element(begin(arr), end(arr));
   std::cout << *max << " " << *min;
   return 0;
}