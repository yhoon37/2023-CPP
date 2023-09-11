#ifndef UNTITLED_DEPARTMENT_H
#define UNTITLED_DEPARTMENT_H
#include "Manager.h"
#include <vector>
#include <algorithm>
using sEmp = std::shared_ptr<Employee>;
using sManager = std::shared_ptr<Manager>;

class Department{
public:
    Department(){}
    Department(string department): department(department){}
    ~Department(){}
    void print() const{
        cout << department << endl;
        manager->print();
        for(auto& employee: employees){
            employee->print();
        }
    }
    void addEmp(sEmp emp){
        employees.push_back(emp);
        sort(employees.begin(), employees.end());   //주소값으로 sorting 하는 듯
    }
    void setManager(sManager manager){this->manager = manager;}
    auto& getEmployees(){return employees;}
private:
    string department;
    shared_ptr<Manager> manager;
    vector<shared_ptr<Employee>> employees;
};


#endif //UNTITLED_DEPARTMENT_H
