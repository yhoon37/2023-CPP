#ifndef UNTITLED_OUTPUTDEVICE_H
#define UNTITLED_OUTPUTDEVICE_H
#include <iostream>
using namespace std;
class OutputDevice{
public:
    OutputDevice(){cout << "OutputDevice constructor" << endl;}
    virtual ~OutputDevice(){cout << "OutputDevice destructor" << endl;}
private:
};

#endif //UNTITLED_OUTPUTDEVICE_H
