#ifndef TICKET_MEMBERSHIP_H
#define TICKET_MEMBERSHIP_H

class Membership{
public:
    Membership(int remainCount): remainCount(remainCount){}
    void use(){remainCount--;}
    bool isAvailable(){return remainCount > 0;}

private:
    int remainCount;
};

#endif //TICKET_MEMBERSHIP_H
