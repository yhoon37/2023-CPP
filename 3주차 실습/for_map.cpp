#include <iostream>
#include <map>


int main() {
    int size;
    std::cin >> size;
    std::map<std::string, std::string> phonebook;
    for(int i=0; i<size; i++){
        std::string name, phonenumber;
        std::cin >> name >> phonenumber;
        phonebook[name] = phonenumber;
    }

    while(true){
        std::string input;
        std::cin >> input;
        if(input == "QUIT") break;
        auto findPerson = phonebook.find(input);
        if(findPerson != phonebook.end())
            std::cout << findPerson->second << std::endl;
        else
            std::cout << "NOT FOUND" << std::endl;
    }
}
