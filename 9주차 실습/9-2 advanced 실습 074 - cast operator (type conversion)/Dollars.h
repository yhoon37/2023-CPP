#ifndef UNTITLED_DOLLARS_H
#define UNTITLED_DOLLARS_H
#include "Cents.h"

class Dollars{
public:
    Dollars(int dollar): dollar(dollar){}
    operator Cents() const{
        return dollar*100;
    }
private:
    int dollar;
};

#endif //UNTITLED_DOLLARS_H
