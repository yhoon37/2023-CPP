#ifndef UNTITLED_LED_MONITOR_H
#define UNTITLED_LED_MONITOR_H

#include "Monitor.h"

class LED_Monitor : public Monitor{
public:
    LED_Monitor() : Monitor(){cout << "LED_Monitor constructor" << endl;}
    ~LED_Monitor(){cout << "LED_Monitor destructor" << endl;}

private:

};

#endif //UNTITLED_LED_MONITOR_H
