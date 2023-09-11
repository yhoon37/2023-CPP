#ifndef TASK6_OBJECTCART_ITEM_H
#define TASK6_OBJECTCART_ITEM_H

#include <string>

class Item {
public:
    Item(std::string name, int quantity, int price)
            : name(name), quantity(quantity), price(price) {
        static int IdCounter=0;
        id = IdCounter++;
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getQuantity() const { return quantity; }
    int getPrice() const { return price; }

private:
    int id;
    std::string name;
    int quantity;
    int price;
};


#endif //TASK6_OBJECTCART_ITEM_H
