#ifndef TICKET_TICKETSELLER_H
#define TICKET_TICKETSELLER_H
#include "Audience.h"
#include "TicketOffice.h"

class TicketSeller{
public:
    TicketSeller(TicketOffice ticketOffice): ticketOffice(ticketOffice){}
    void sellTo(Audience audience){
        int fee = audience.buy(ticketOffice.getTicket());
        ticketOffice.plusAmount(fee);
    }

private:
    TicketOffice ticketOffice;
};

#endif //TICKET_TICKETSELLER_H
