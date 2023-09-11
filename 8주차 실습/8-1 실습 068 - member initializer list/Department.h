#ifndef UNTITLED_DEPARTMENT_H
#define UNTITLED_DEPARTMENT_H
#include "Faculty.h"
#include <iostream>

class Department{
    private:
        std::string name;
        Faculty* faculty=nullptr;

    public:
    Department(std::string name, Faculty* faculty): name(name), faculty(faculty){
        faculty->setDept(this);
    }
    Department(std::string name){
        this->name = name;
        Faculty* a = new Faculty;
        faculty = a;
        faculty->setDept(this);
    }

    void setFaculty(Faculty* faculty){
        this->faculty = faculty;
    }

    Faculty* getFaculty(){return faculty;}
    std::string getName(){return name;}
};

#endif //UNTITLED_DEPARTMENT_H
