#include "Theater.h"


int main() {
    std::vector<Ticket> tickets {{10'000}, {10'000}, {10'000}};
    TicketOffice ticketOffice{tickets};
    TicketSeller ticketSeller{ticketOffice};
    Theater theater {ticketSeller};

    Audience audience {100'000, {3}};
    theater.enter(audience);
}