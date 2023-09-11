#include "SharedPreferences.h"

SharedPreferences& SharedPreferences::getInstance(){//만약 &로 반환하지 않으면?
    static SharedPreferences sharedPreferences;
    return sharedPreferences;
}

void SharedPreferences::putInt(std::string key, int value){
    preferences.insert({key, value});
}

int SharedPreferences::getInt(std::string key){
    return preferences[key];
}

size_t SharedPreferences::size(){
    return preferences.size();
}