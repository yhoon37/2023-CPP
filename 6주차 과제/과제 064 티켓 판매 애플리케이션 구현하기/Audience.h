#ifndef TICKET_AUDIENCE_H
#define TICKET_AUDIENCE_H
#include "Membership.h"
#include "Ticket.h"

class Audience{
public:
    Audience(long amount, Membership membership): amount(amount), membership{membership}{}

    int buy(Ticket ticket){
        if(membership.isAvailable()){
            membership.use();
            this->ticket = ticket;
            return 0;
        }
        else{
            amount -= ticket.getFee();
            this->ticket = ticket;
            return ticket.getFee();
        }
    }

private:
    long amount;
    Membership membership;
    Ticket ticket;
};

#endif //TICKET_AUDIENCE_H
