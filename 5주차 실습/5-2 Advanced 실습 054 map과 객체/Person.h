#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H
#include <string>

class Person {
public:
    Person(std::string name, std::string number);
    void modifyNumber(std::string number);
    void print() const;

private:
    std::string name;
    std::string number;
};

#endif //UNTITLED_PERSON_H
