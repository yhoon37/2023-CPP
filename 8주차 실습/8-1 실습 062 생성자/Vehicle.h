#ifndef UNTITLED_VEHICLE_H
#define UNTITLED_VEHICLE_H

#include <string>
class Vehicle {
public:
    Vehicle(std::string name, int range, bool hasFDS, float batteryCapacity);
    Vehicle(std::string name, int range, float batteryCapacity);
    Vehicle();
    void autoPilot(bool onOff);
    void runFDS() const;
    void displayEfficiency() const;
private:
    std::string name;
    int range;
    bool hasFDS;
    float batteryCapacity;
};

#endif //UNTITLED_VEHICLE_H
