#include "Temperature.h"
#include <iomanip>
#include <sstream>

Temperature::Temperature(double temp, SCALE scale){
        this->temperature = temp;
        this->scale = scale;
}

std::string Temperature::print() const{
    std::stringstream ss;
    ss << std::fixed;
    ss << std::setprecision(1);
    if (this->scale == FAHRENHEIT) {
        ss << this->temperature << " F\n";
    } else {
        ss << this->temperature << " C\n";
    }
    return ss.str();
}

void Temperature::convertToCelsius(){
    this->temperature = ((this->temperature) - 32)*5/9;
    this->scale = CELSIUS;
}

void Temperature::convertToFahrenheit(){
    this->temperature = (this->temperature)*9/5 + 32;
    this->scale = FAHRENHEIT;
}

Temperature Temperature::add(Temperature other){

    if(this->scale != other.scale){
        if(this->scale == CELSIUS){
            other.convertToCelsius();
        }
        else{
            other.convertToFahrenheit();
        }
    }
    double add_temp = this->temperature + other.temperature;

    return Temperature{add_temp, this->scale};
}