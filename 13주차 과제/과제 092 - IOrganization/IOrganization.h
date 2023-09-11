#ifndef UNTITLED_IORGANIZATION_H
#define UNTITLED_IORGANIZATION_H
#include <memory>
#include "Employee.h"
#include "Department.h"
#include "Manager.h"

using sEmp = std::shared_ptr<Employee>;
using sDept = std::shared_ptr<Department>;
using sManager = std::shared_ptr<Manager>;

class IOrganization {
public:
    virtual ~IOrganization() {}
    virtual void addDept(sDept dept) = 0;
    virtual void addEmpToDept(sDept dept, sEmp emp) = 0;
    virtual void setDeptManager(sDept dept, sManager manager) = 0;
    virtual bool moveEmp(sDept &from_dept, sDept &to_dept, sEmp emp) = 0;
    virtual void print() const = 0;
};

#endif //UNTITLED_IORGANIZATION_H
