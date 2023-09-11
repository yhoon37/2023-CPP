#ifndef UNTITLED_MONITOR_H
#define UNTITLED_MONITOR_H

#include "OutputDevice.h"

class Monitor : public OutputDevic{
public:
    Monitor(): OutputDevic(){cout << "Monitor constructor" << endl;}
    ~Monitor(){cout << "Monitor destructor" << endl;}

private:

};

#endif //UNTITLED_MONITOR_H
