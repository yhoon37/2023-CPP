#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Person {
public:
    Person(std::string name, size_t age) : name{name}, age{age} {
        ID = id++;
    }

    friend std::ostream& operator << (std::ostream& out, const Person& p) {
        out << p.ID << " " << p.name << " " << p.age;
    }

    bool operator < (const Person& rhs) const {
        return ID < rhs.ID;
    }

    class ComparatorByAge {
    public:
        bool operator()(const Person& lhs, const Person& rhs) const{
            return lhs.age < rhs.age;
        }
    };

    class ComparatorByName {
    public:
        bool operator()(const Person& lhs, const Person& rhs) const{
            return lhs.name < rhs.name;
        }
    };

private:
    static int id;
    long long ID;
    std::string name;
    size_t age;
};

int Person::id =1;
#endif //UNTITLED_PERSON_H
