#include "Person.h"
#include <iostream>
#include <map>

int main() {
    int size;
    std::cin >> size;
    std::map<std::string, Person> numberBook;

    for(int i=0; i<size; i++){
        std::string name, number;
        std::cin >> name >> number;
        if(numberBook.find(name) == numberBook.end()){
            Person data(name, number);
            //1번 방법
           /* std::pair<std::string, Person> da = {name, data};
            numberBook.insert(da);  */
            //2번 방법
            //numberBook[name] = data;    //왜 안되는거얌
            //3번 방법
            numberBook.insert({name, data});
        }
    }

    std::string command;
    while(true){
        std::cin >> command;
        if(command == "ADD"){
            std::string name, number;
            std::cin >> name >> number;

            if(numberBook.find(name) == numberBook.end()){
                Person newData(name, number);
                numberBook.insert({name, newData});
            }
        }
        else if(command == "DEL"){
            std::string name;
            std::cin >> name;
            auto remove = numberBook.find(name);
            if(remove != numberBook.end()){
                numberBook.erase(remove);
            }
        }
        else if(command == "MOD"){
            std::string name;
            std::cin >> name;
            auto modify = numberBook.find(name);
            if(modify != numberBook.end()){
                std::string number;
                std::cin >> number;
                modify->second.modifyNumber(number);
            }
        }
        else if(command == "FIN"){
            std::string name;
            std::cin >> name;
            auto find = numberBook.find(name);
            if(find != numberBook.end()){
                find->second.print();
            }
        }
        else if(command == "QUI"){
            break;
        }
    }
    for(auto& list : numberBook){
        list.second.print();
    }
    return 0;
}