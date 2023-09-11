#ifndef UNTITLED_MANAGER_H
#define UNTITLED_MANAGER_H
#include "Employee.h"

class Manager: public Employee{
public:
    Manager(){}
    Manager(string name, int salary): Employee(name, salary){}
    ~Manager(){}
    void print() const override {cout << "\t|---Manager: " << Employee::getName() << " " << Employee::getID() << " " << Employee::getSalary() << endl;}
private:

};


#endif //UNTITLED_MANAGER_H
