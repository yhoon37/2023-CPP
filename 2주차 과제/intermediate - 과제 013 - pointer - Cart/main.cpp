#include <iostream>

struct Item {
    int id;
    std::string name;
    int quantity;
    int price;
};

int main() {
    int item_count = 0;

    Item *cart = nullptr;

    int a = 0;
    std::cin >> a;

    Item* nItem = new Item;

    nItem->id = item_count;

    std::cout << "Enter item name: ";
    std::cin >> nItem->name;

    std::cout << "Enter item quantity: ";
    std::cin >> nItem->quantity;

    std::cout << "Enter item price: ";
    std::cin >> nItem->price;

    cart = nItem;

    std::cout << "Item " << item_count << " added successfully."<<std::endl;

    item_count ++;

    while (true) {
        int select=0;
        std::cout << "1. Add item" << std::endl;

        std::cout << "2. Delete item" << std::endl;

        std::cout << "3. View item details" << std::endl;

        std::cout << "4. View total cost" << std::endl;

        std::cout << "5. Quit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> select;

        if(select == 1){
            Item* newItem = new Item;

            newItem->id = item_count;

            std::cout << "Enter item name: ";
            std::cin >> newItem->name;

            std::cout << "Enter item quantity: ";
            std::cin >> newItem->quantity;

            std::cout << "Enter item price: ";
            std::cin >> newItem->price;

            if(item_count == 0)
                cart = newItem;

            else{
                Item* itemArr = new Item[item_count+1];

                for(int i=0; i<item_count; i++){
                    (itemArr+i)->id = (cart+i)->id;
                    (itemArr+i)->name = (cart+i)->name;
                    (itemArr+i)->quantity = (cart+i)->quantity;
                    (itemArr+i)->price = (cart+i)->price;
                }
                if(item_count == 1)
                    delete cart;
                else{
                    delete[] cart;
                }

                (itemArr+item_count)->id = newItem->id;
                (itemArr+item_count)->name = newItem->name;
                (itemArr+item_count)->quantity = newItem->quantity;
                (itemArr+item_count)->price = newItem->price;

                cart = itemArr;
            }

            std::cout << "Item " << item_count << " added successfully."<<std::endl;

            item_count ++;
        }

        if(select==2){
            int delItem = 0;
            std::cout << "Enter item ID: ";
            std::cin >> delItem;
            //카트에있는 아이템 제거하고 한칸씩 옴기기, 여기서 마지막 칸은 제거를 안했음
            (cart+delItem)->quantity = 0;
//            for(int i=delItem; i<item_count-1; i++){
//
//                (cart+i)->name = (cart+i+1)->name;
//                (cart+i)->quantity = (cart+i+1)->quantity;
//                (cart+i)->price = (cart+i+1)->price;
//            }
            //item_count --;
            //cart+item_count = nullptr;
            std::cout << "Item deleted successfully."<<std::endl;
        }

        if(select==3){
            int itemNum = 0;
            std::cout << "Enter the item number: ";
            std::cin >> itemNum;
            if(cart[itemNum].quantity == 0){
                std::cout << "Item not found"<<std::endl;
            }
            else{
                std::cout << "Item "<< itemNum << ":" << std::endl;
                std::cout << "Name: " << cart[itemNum].name << std::endl;
                std::cout << "Quantity: " << cart[itemNum].quantity << std::endl;
                std::cout << "Price: " << cart[itemNum].price << std::endl;
            }
        }

        if(select==4){
            int total = 0;
            for(int i=0; i<item_count; i++){
                total += cart[i].quantity * cart[i].price;
            }
            std::cout << "Total cost: " << total << std::endl;
        }

        if(select==5){
            delete[] cart;
            break;
        }
    }
    return 0;
}
