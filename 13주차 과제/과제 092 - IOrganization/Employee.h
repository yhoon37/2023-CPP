#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee{
public:
    static int id;
    Employee(){}
    Employee(string name, int salary): name(name), salary(salary){ID = id++;}
    virtual ~Employee(){}
    virtual void print() const {cout << "\t|--- " << name << " " << ID << " " << salary << endl;}
    string getName() const {return name;}
    int getSalary() const {return salary;}
    int getID() const {return ID;}
private:
    string name;
    int salary;
    int ID;
};
int Employee::id = 1;
#endif //UNTITLED_EMPLOYEE_H
