#ifndef UNTITLED_CENTS_H
#define UNTITLED_CENTS_H

class Cents{
public:
    Cents(int cent): cent(cent){}
    operator int() const{
        return cent;
    }
private:
    int cent;
};

#endif //UNTITLED_CENTS_H
