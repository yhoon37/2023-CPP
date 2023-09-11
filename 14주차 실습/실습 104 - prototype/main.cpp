#include <iostream>
#include <map>
#include <memory>

using namespace std;

// class Monster
class Monster{
public:
    virtual void roar() = 0 ;
    virtual std::unique_ptr<Monster> clone() = 0;
private:
};

// class Dragon : public Monster
class Dragon : public Monster{
public:
    void roar(){cout << "Dragon roars!" << endl;}
    std::unique_ptr<Monster> clone(){return std::make_unique<Dragon>(*this);}
private:
};


// class Goblin : public Monster
class Goblin: public Monster{
public:
    void roar(){cout << "Goblin roars!" << endl;}
    std::unique_ptr<Monster> clone(){return std::make_unique<Goblin>(*this);}
private:
};

std::map<std::string, std::unique_ptr<Monster>> monsterRegistry;

void loadMonsters() {
    // Read monster information from file (this is the costly operation)
    // Here, we just pretend to do it and create a Dragon and a Goblin

    monsterRegistry["Dragon"] = std::make_unique<Dragon>();
    monsterRegistry["Goblin"] = std::make_unique<Goblin>();
}

std::unique_ptr<Monster> spawnMonster(const std::string& type) {
    // implement your code
    return monsterRegistry[type]->clone();

}

int main() {
    loadMonsters(); // load monster prototypes

    std::unique_ptr<Monster> dragon1 = spawnMonster("Dragon"); // clone from prototype
    dragon1->roar();

    std::unique_ptr<Monster> goblin1 = spawnMonster("Goblin"); // clone from prototype
    goblin1->roar();

    return 0;
}