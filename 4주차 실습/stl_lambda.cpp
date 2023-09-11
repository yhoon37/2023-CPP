#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


struct Item {
    std::string name;
    double price;
    int quantity;
};

bool compare(Item a,Item b){
    return a.price < b.price;
}
void item_find(std::vector<Item> inventory, std::string str) {
    auto find = std::find_if(inventory.begin(), inventory.end(),
                             [str](Item item){return item.name == str;});
    if(find != inventory.end())
        std::cout << "Item found " << find->name << " " << find->price << " " << find->quantity << std::endl;
}

void item_count(std::vector<Item> inventory, double price){
    int count = std::count_if(inventory.begin(), inventory.end(), [price](Item item){return item.price > price;});
    std::cout << "Number of expensive items: " << count << std::endl;
}

void item_remove(std::vector<Item>& inventory){
    inventory.erase(std::remove_if(inventory.begin(), inventory.end(),
                                   [](Item item){return item.quantity == 0;}), inventory.end());
    //inventory.erase 없이 그냥 remove_if 쓰면 어떻게 되는지
}

int main() {
    std::vector<Item> inventory = {
            {"Apple", 0.99, 10},
            {"Banana", 0.59, 20},
            {"Cherry", 1.49, 5},
            {"Dates", 2.99, 2},
            {"Elderberry", 3.99, 0},
            {"Fig", 2.49, 15},
            {"Grape", 0.79, 25},
            {"Honeydew", 1.29, 8},
            {"Indian Gooseberry", 2.99, 0},
            {"Jackfruit", 4.99, 1}};


    std::sort(inventory.begin(), inventory.end(), compare);
    std::for_each(inventory.begin(), inventory.end(),
                  [](Item item){std::cout << item.name << " " << item.price << " " << item.quantity << std::endl;});
    item_find(inventory, "Grape");
    item_count(inventory, 2.0);
    item_remove(inventory);
    std::for_each(inventory.begin(), inventory.end(),
                  [](Item item){std::cout << item.name << " " << item.price << " " << item.quantity << std::endl;});

    return 0;

}
