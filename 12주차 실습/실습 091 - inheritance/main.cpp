#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    Person(string name): name(name){cout << "Person is constructed!" << endl;}
    ~Person(){cout << "Person is destructed!";}
    void print(){
        cout << "Person Name: " << name << endl;
    }

protected:
    string name;
};

class Student : public Person{
public:
    Student(string name, string school): Person(name), school(school){cout << "Student is constructed!" << endl;}
    ~Student(){cout << "Student is destructed!";}
    void print(){
        cout << "Person Name: " << name << endl;
        cout << "School Name: " << school << endl;
    }
private:
    string school;
};

int main() {
    Person p1{"Park"};
    p1.print();

    Student s1 {"Kim", "PNU"};
    s1.print();

    return 0;
}