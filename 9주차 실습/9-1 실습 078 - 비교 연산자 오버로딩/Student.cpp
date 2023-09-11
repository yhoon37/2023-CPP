#include "Student.h"

bool Student::operator<(const Student& other) const{
    return name < other.name;
}

ostream& operator<<(ostream& os, const Student& student){
    os << "Id: " << student.getId() << " Name: " << student.getName() << " Grade: " << student.getGrade();
    return os;
}

bool compareByGrade(const Student& a, const Student& b){
    return a.grade > b.grade;
}