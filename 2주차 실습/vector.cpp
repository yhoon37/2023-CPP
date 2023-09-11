#include <iostream>
#include <vector>

int main() {
    int size=0, quiz=0;
    std::cin >> size >> quiz;
    std::cin.ignore();
    std::vector<std::vector<int>> vec(size);
    for(int i=0; i<size; i++){

        int column=0;
        std::cin >> column;

        for(int j=0; j<column; j++){
            int a = 0;
            std::cin >> a;
            vec[i].push_back(a);
        }
    }
    for(int i=0; i<quiz; i++){
        int row=0, column = 0;
        std::cin >> row >> column;
        std::cout << vec[row][column] << std::endl;
    }
    return 0;
}
