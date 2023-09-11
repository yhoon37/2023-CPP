#include <iostream>
#include <string>
#include <vector>
#include <functional>
struct Champion {
    std::string name;
    int health;
    int attack;
};
auto findChampionMoreThanHealth(std::vector<Champion> champions, int health) {
}
auto findChampionMoreThanAttack(std::vector<Champion> champions, int attack) {
}
auto findChampionWithCondition(std::vector<Champion> champions, std::function<bool(Champion)> condition) {
}
void printChampion(const std::vector<Champion> champions){
}
std::vector<Champion> createChampion() {
    std::vector<Champion> champions;
    Champion tryndamere {"Tryndamere", 625, 72};
    Champion kled {"Kled", 740, 35};
    Champion garen {"Garen", 620, 66};
    champions.push_back(tryndamere);
    champions.push_back(kled);
    return champions;
}