#ifndef UNTITLED_ORGANIZATION_H
#define UNTITLED_ORGANIZATION_H
#include <algorithm>
#include "IOrganization.h"
#include "Department.h"

class Organization : public IOrganization{
public:
    Organization(string organization): IOrganization(), organization(organization){}
    ~Organization(){}
    void addDept (sDept dept) override {Depts.push_back(dept);}
    void addEmpToDept(sDept dept, sEmp emp) override {
        auto found = find(Depts.begin(), Depts.end(), dept);
        if(found != Depts.end()){
            (*found)->addEmp(emp);
        }
    }
    void setDeptManager(sDept dept, sManager manager) override {
        auto findEmp = find(Depts.begin(), Depts.end(), dept);
        if(findEmp != Depts.end()){
            (*findEmp)->setManager(manager);
        }
    }
    bool moveEmp(sDept &from_dept, sDept &to_dept, sEmp emp) override {
        auto findEmp = find_if(from_dept->getEmployees().begin(), from_dept->getEmployees().end(),
                             [emp](auto& employee){return employee->getName() == emp->getName();});
        if(findEmp != from_dept->getEmployees().end()){
            from_dept->getEmployees().erase(findEmp);
            to_dept->addEmp(emp);
            return true;
        }
        else{ return false;}
    }
    void print() const override {
        cout << "Organization: " << organization << endl;
        for(auto& dept: Depts){
            dept->print();
        }
    }

private:
    string organization;
    vector<shared_ptr<Department>> Depts;
};

#endif //UNTITLED_ORGANIZATION_H
