#include "Checkout.h"

int Checkout::calculateTotalPrice(std::vector<Item>::const_iterator begin,
                        std::vector<Item>::const_iterator end) const{
    int total=0;
    for(auto i = begin; i<=end; i++){
        total += (i->getQuantity()) * (i->getPrice());
    }
    if(discountCode == NO_DISCOUNT){
        total = total;
    }
    else if(discountCode == DISCOUNT_20){
        total *= 0.8;
    }
    else if(discountCode == DISCOUNT_50){
        total *= 0.5;
    }
    return total;
}

void Checkout::setShippingAddress(const std::string &shippingAddress){
    this->shippingAddress = shippingAddress;
}

void Checkout::setDiscountCode(DiscountCode discountCode){
    this->discountCode = discountCode;
}