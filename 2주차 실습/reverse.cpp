#include <iostream>

int main() {
    int size =0;
    std::cin >> size;
    int arr[size];
    for(int  i=0; i<size; i++){
        std::cin >> arr[i];
    }
    for(int i=size-1; i>=0; i--){
        std::cout << arr[i] << " ";
    }
    return 0;
}