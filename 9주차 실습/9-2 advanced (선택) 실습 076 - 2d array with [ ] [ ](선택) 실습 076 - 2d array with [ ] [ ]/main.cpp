#include <iostream>
#include "ChessBoard.h"

int main() {
    std::cout << PIECE(1) << std::endl;

    ChessBoard c;
    std::cout << c << std::endl;
    std::cout << c[0][0] << std::endl;
    std::cout << c[0][1] << std::endl;

    return 0;
}