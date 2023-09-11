#ifndef TICKET_TICKET_H
#define TICKET_TICKET_H

class Ticket{
public:
    Ticket() {}
    Ticket(int fee): fee(fee){}
    int getFee(){return fee;}

private:
    int fee;
};

#endif //TICKET_TICKET_H
