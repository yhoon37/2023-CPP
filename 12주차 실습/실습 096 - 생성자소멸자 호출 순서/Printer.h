#ifndef UNTITLED_PRINTER_H
#define UNTITLED_PRINTER_H

#include "OutputDevice.h"

class Printer : public OutputDevic{
public:
    Printer(): OutputDevic(){cout << "Printer constructor" << endl;}
    ~Printer(){cout << "Printer destructor" << endl;}

private:

};

#endif //UNTITLED_PRINTER_H
