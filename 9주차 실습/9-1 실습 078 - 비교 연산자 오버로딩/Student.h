#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <iostream>

using namespace std;

class Student{
    private:
    int id;
    string name;
    int grade;

public:
    Student(){}
    Student(int id, string name, int grade): id(id), name(name), grade(grade){}
    int getId() const {return id;}
    string getName() const {return name;}
    int getGrade() const {return grade;}
    bool operator<(const Student& other) const;
    friend ostream& operator << (ostream& os, const Student& student);
    friend bool compareByGrade(const Student& a, const Student& b);
};

ostream& operator << (ostream& os, Student& student);

bool compareByGrade(const Student& a, const Student& b);


#endif //UNTITLED_STUDENT_H
