#ifndef UNTITLED_LCD_MONITOR_H
#define UNTITLED_LCD_MONITOR_H

#include "Monitor.h"

class LCD_Monitor : public Monitor{
public:
    LCD_Monitor() : Monitor(){cout << "LCD_Monitor constructor" << endl;}
    ~LCD_Monitor(){cout << "LCD_Monitor destructor" << endl;}

private:

};

#endif //UNTITLED_LCD_MONITOR_H
