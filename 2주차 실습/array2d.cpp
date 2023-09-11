#include <iostream>

int main() {
    int row =0, column = 0;
    std::cin >> row;
    std::cin >> column;
    int arr[row][column];
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            std::cin >> arr[i][j];
        }
        std::cout << std::endl;
    }
    for(int i=0; i<row; i++){
        int sum=0;
        for(int j=0; j<column; j++){
            sum += arr[i][j];
        }
        std::cout << sum << " ";
    }
    std::cout << std::endl;
    for(int j=0; j<column; j++){
        int sum=0;
        for(int i=0; i<row; i++){
            sum += arr[i][j];
        }
        std::cout << sum << " ";
    }
    return 0;
}