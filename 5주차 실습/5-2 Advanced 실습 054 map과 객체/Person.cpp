#include "Person.h"
#include <iostream>

Person::Person(std::string name, std::string number) {
   this->name = name;
   this->number = number;
}

void Person::modifyNumber(std::string number) {
    this->number = number;
}

void Person::print() const {
    std::cout << name + " " + number << std::endl;
}
