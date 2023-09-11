#include "Temperature.h"
#include <iostream>


SCALE getScale(char scale) {
    return scale == 'C' ? CELSIUS : FAHRENHEIT;
}

Temperature createTemperatureFromKeyboard(){
    float degree;
    char scale;
    std::cin >> degree >> scale;
    return Temperature {degree, getScale(scale)};
}

int main() {
    Temperature t1 = createTemperatureFromKeyboard();
    std::cout << t1.print();

    Temperature t2 = createTemperatureFromKeyboard();
    std::cout << t2.print();

    Temperature t3 = t1.add(t2);
    std::cout << t3.print();

    Temperature t4 = t2.add(t1);
    std::cout << t4.print();

    Temperature t5 = t3.add(t4);
    std::cout << t5.print();

    return 0;
}