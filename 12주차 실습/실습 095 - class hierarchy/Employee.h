#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee {
public:
    Employee(string name, int salary) : name_(name), salary_(salary) {}
    virtual void print_report() const {
        cout << "Name: " << name_ << endl;
        cout << "Salary: " << salary_ << endl;
        cout << "Years of service: " << years_of_service_ << endl;
        cout << "Performance score: " << performance_score_ << endl;
    }
    string get_name() const {
        return name_;
    }
protected:
    string name_;
    int salary_;
    int years_of_service_ = 0;
    int performance_score_ = 0;
};

class Manager : public Employee{
public:
    Manager(string name, int salary, string department): Employee(name, salary), department(department){}
    void set_goals(){
        cout << "Set goals for " << department << endl;
    }
    void print_report() const{
        Employee::print_report();
        cout << "Department: " << department << endl;
    }
private:
    string department;
};

class Programmer : public Employee{
public:
    Programmer(string name, int salary, string language): Employee(name, salary), language(language){performance_score_ = 10;}
    void write_code(){
        cout << "Writing code in " << language << endl;
    }
    void print_report() const{
        Employee::print_report();
        cout << "Language: " << language << endl;
    }
private:
    string language;
};

class Salesperson : public Employee{
public:
    Salesperson(string name, int salary, int sales): Employee(name, salary), sales(sales){performance_score_=20;}
    void sell(){
        cout << "Selling products, generated " << sales << " in revenue" << endl;
    }
    void print_report() const{
        Employee::print_report();
        cout << "Sales: " << sales << endl;
    }
private:
    int sales;
};

#endif //UNTITLED_EMPLOYEE_H
