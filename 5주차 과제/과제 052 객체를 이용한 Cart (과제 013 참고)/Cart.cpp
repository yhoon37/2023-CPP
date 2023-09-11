#include "Cart.h"
#include <algorithm>
#include <iostream>

using const_iterator = std::vector<Item>::const_iterator;

void Cart::addItem(const Item& item){items.push_back(item);}

void Cart::deleteItem(int id){
    items.erase(std::remove_if(items.begin(), items.end(), [id](Item item){return item.getId() == id;}),items.end());
}

int Cart::checkout(){
    auto begin = this->cbegin();
    auto end = this->cend();
    //이렇게 하면 에러 날듯
    //checkout_->calculateTotalPrice(this->cbegin(), this->cend());
    return checkout_->calculateTotalPrice(begin, end);
}

void Cart::viewItemDetails(int id, std::ostream& out) const{
    auto find = std::find_if(items.begin(), items.end(), [id](Item item){return item.getId() == id;});
    if(find != items.end()){
        out << "Item " << find->getId() <<":\nName: " << find->getName() << "\n\tQuantity: " << find->getQuantity()
        << "\nPrice: " << find->getPrice() << std::endl;
    }
    else{
        out << "Item not found." << std::endl;
    }
}

const_iterator Cart::cbegin() const{return items.begin();}

const_iterator Cart::cend() const{return items.end()-1;}