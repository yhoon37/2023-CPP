
#ifndef TICKET_THEATER_H
#define TICKET_THEATER_H
#include "Audience.h"
#include "TicketSeller.h"

class Theater{
public:
    Theater(TicketSeller ticketSeller): ticketSeller(ticketSeller){}
    void enter(Audience audience){
        ticketSeller.sellTo(audience);
    }

    TicketSeller getTicketSeller(){return ticketSeller;}
private:
    TicketSeller ticketSeller;
};

#endif //TICKET_THEATER_H
