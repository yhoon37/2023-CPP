#include <iostream>

void my_swap(int & m, int & n) {
    int temp = n;
    n = m;
    m = temp;
    return ;
}

int main() {

    int m, n;

    std::cin >> m >> n;

    my_swap(m, n);

    std::cout << m << " " << n;

}