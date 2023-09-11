#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <iostream>
#include <string>
#include <tuple>


enum GRADE {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};

class Student {
public:
    Student(std::string name, GRADE grade) : name(name), grade(grade) {}

    friend std::ostream& operator << (std::ostream& os, const Student& s){
        os << s.grade << "학년, " << s.name;
        return os;
    }

    friend class Compare;
    class Compare{
    public:
        bool operator () (Student& lhs, Student& rhs){
            if(lhs.grade < rhs.grade) return true;
            else if(lhs.grade == rhs.grade && lhs.name < rhs.name) return true;
            return false;
        }
    };

private:
    std::string name;
    GRADE grade;
};

#endif //UNTITLED_STUDENT_H
