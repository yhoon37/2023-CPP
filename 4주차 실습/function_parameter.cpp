#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>

struct Champion {
    std::string name;
    int health;
    int attack;
};

auto findChampionWithCondition(std::vector<Champion> champions, std::function<bool(Champion)> condition) {
    std::vector<Champion> result;
    for (auto& c : champions)
        if(condition(c))
            result.push_back(c);
    return result;
}

void printChampion(const std::vector<Champion> champions){
    for(const auto& it: champions){
        std::cout << it.name << " " << it.health << " " << it.attack << std::endl;
    }
}

std::vector<Champion> createChampion() {
    std::vector<Champion> champions;
    Champion tryndamere {"Tryndamere", 625, 72};
    Champion kled {"Kled", 740, 35};
    Champion garen {"Garen", 620, 66};
    champions.push_back(tryndamere);
    champions.push_back(kled);
    champions.push_back(garen);
    return champions;
}

int main() {
    std::string str1, str2;
    int check;
    std::cin >> str1;

    auto delimiter = str1.rfind(":");
    str2 = str1.substr(delimiter+1, str1.size()-delimiter);
    str1 = str1.substr(0, delimiter);

    check = std::stoi(str2);

    auto champions = createChampion();
    std::vector<Champion> result;

    std::function<bool(Champion)> health = [check] (Champion c) { return c.health > check; };
    std::function<bool(Champion)> attack = [check] (Champion c) { return c.attack > check; };

    if(str1 == "health")
        result = findChampionWithCondition (champions, health);
    else if(str1 == "attack")
        result = findChampionWithCondition (champions, attack);

    printChampion(result);
    return 0;

}
