#ifndef UNTITLED_MONITOR_H
#define UNTITLED_MONITOR_H
// operator unique_ptr begin
#include "OutputDevice.h"

class Monitor : public OutputDevice{
public:
    Monitor(): OutputDevice(){cout << "Monitor constructor" << endl;}
    virtual ~Monitor(){cout << "Monitor destructor" << endl;}

private:

};

#endif //UNTITLED_MONITOR_H
