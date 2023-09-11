#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Car{
public:
    Car(string name=""):name(name){}
    virtual void accelerate() = 0;
    virtual void brake() = 0;

protected:
    string name;
    int speed=0;
};

class GV70:public Car{
public:
    GV70(string name="gv70") : Car(name){}
    void accelerate(){cout << "The speed of the " << name << " has increased by 30 km/h." <<endl; speed+=30;}
    void brake(){speed=0;}
private:
};

class Grandeur:public Car{
public:
    Grandeur(string name="grandeur") : Car(name){}
    void accelerate(){cout << "The speed of the " << name << " has increased by 20 km/h." <<endl; speed+=20;}
    void brake(){speed=0;}
private:
};

class Carnibal:public Car{
public:
    Carnibal(string name="carnibal") : Car(name){}
    void accelerate(){cout << "The speed of the " << name << " has increased by 10 km/h." <<endl; speed+=10;}
    void brake(){speed=0;}
private:
};

unique_ptr<Car> make_vehicle() {

    std::string choice;
    cin >> choice;
    if (choice == "gv70") return make_unique<GV70>();
    else if (choice == "grandeur") return make_unique<Grandeur>();
    else if (choice == "carnibal") return make_unique<Carnibal>();
    else make_unique<GV70>();

}

int main() {

    std::vector<unique_ptr<Car>> test_vehicles;

    test_vehicles.push_back(make_vehicle()); //gv70

    test_vehicles.push_back(make_vehicle()); //grandeur

    test_vehicles.push_back(make_vehicle()); //carnibal

    for (auto& v : test_vehicles)

        (*v).accelerate();

}