
#ifndef UNTITLED_FACULTY_H
#define UNTITLED_FACULTY_H
#include <iostream>
#include "Department.h"

class Department;

class Faculty{
    private:
    std::string name;
    int numMember;
    Department* departments=nullptr;

public:
    Faculty(std::string name, int numMember): name(name), numMember(numMember){}
    Faculty(){name = "N/A"; numMember=0;}
    std::string getName(){return name;}
    int getNum(){return numMember;}
    Faculty* get(){return this;}
    Department* getDept(){return departments;}
    void setDept(Department* dept){departments = dept;}
};

#endif //UNTITLED_FACULTY_H
