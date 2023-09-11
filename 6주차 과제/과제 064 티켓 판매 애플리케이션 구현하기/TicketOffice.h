#ifndef TICKET_TICKETOFFICE_H
#define TICKET_TICKETOFFICE_H
#include "Ticket.h"
#include <vector>

class TicketOffice{
public:
    TicketOffice(std::vector<Ticket> tickets) : tickets(tickets){}
    Ticket getTicket(){
        Ticket ticket = *tickets.begin();
        tickets.erase(tickets.begin());
        return ticket;
    }
    void plusAmount(int fee){amount += fee;}
private:
    std::vector<Ticket> tickets;
    long amount;
};

#endif //TICKET_TICKETOFFICE_H
