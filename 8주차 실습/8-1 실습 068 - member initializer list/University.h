#ifndef UNTITLED_UNIVERSITY_H
#define UNTITLED_UNIVERSITY_H
#include "Department.h"
using namespace std;
class University{
private:
    std::string name;
    int numDepartments;
    Department* departments;

public:
    University(std::string name, int numDepartments): name(name), numDepartments(numDepartments){}

    void setDepartments(Department* departments){this->departments = departments;}
    void printInfo(){
        cout << "University Name: " << name << endl;
        cout << "Number of Departments: " << numDepartments << endl << endl;
        for(int i=0; i<numDepartments; i++){
            std::string fName = (departments+i)->getFaculty()->getName();
            cout << "Department Name: " << (departments+i)->getName() << endl;
            cout << "Faculty Name: " << fName << endl;
            cout << "Number of Faculty Members: ";
            if(fName == "N/A")
                cout << "N/A" << endl << endl;
            else
                cout << (departments+i)->getFaculty()->getNum() << endl << endl;
        }
    }
};

#endif //UNTITLED_UNIVERSITY_H
