#include <iostream>
#include <map>

void addItem(std::map<std::string, int>& inventory, std::string item, int count) {

    inventory[item] += count;
}

void addItem(std::map<std::string, int>& inventory, std::string item, float money) {

    inventory[item] += 1;
    inventory["MONEY"] += money;
}

int main(){
    std::map<std::string, int> inventory;
    addItem(inventory, "sword", 1);
    addItem(inventory, "shield", 2);
    addItem(inventory, "shield", 5.0F);
    addItem(inventory, "armor", 3.0F);

    for (const auto &[key, value] : inventory)
        std::cout << key << " " << value << std::endl;
}
