#include <iostream>
#include <vector>


int main() {
   int size = 0, sum=0;
   std::cin >> size;
   std::vector<int> vec(size);
   for(int i=0; i<size; i++){
       int num=0;
       std::cin >> num;
       vec.push_back(num);
   }
   for(auto i: vec){
       sum += i;
   }
   std::cout << sum;
}
