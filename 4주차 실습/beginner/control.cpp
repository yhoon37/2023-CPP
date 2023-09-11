#include <iostream>
#include <map>
#include <regex>
#include <vector>
#include <algorithm>

bool compare(std::pair<std::string, int>a, std::pair<std::string, int>b){
    return a.second > b.second;
}

int main(){
    std::string str;
    std::map<std::string, int> words;

    while(std::cin >> str && str != "^"){
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::string filtered{std::regex_replace(str, std::regex("[.|,|:|;|]"), "")};

        if(words.find(filtered) != words.end()){
            words[filtered]++;
        }
        else{
            words.insert({filtered, 1});
        }
    }

    std::vector<std::pair<std::string, int>> words_vector;
    for(auto& it: words){
        words_vector.push_back(it);
    }

    std::sort(words_vector.begin(), words_vector.end(), compare);

    std::cout << "# of words: " << words.size() << std::endl;
    std::cout << "Top 5 Words Frequencies" << std::endl;
    for(int i =0; i<5 ; i++){
        std::cout << i+1 << " " << words_vector[i].first << ": " << words_vector[i].second << std::endl;
    }

    std::cout << "Find Word Frequencies" << std::endl;

    while(std::cin >> str && str !="QUIT"){
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(words.find(str) != words.end()){
            std::cout << str << ": " << words[str] << std::endl;
        }
        else{
            std::cout << str << ": 0" <<std::endl;
        }
    }
    std::cout << "Bye!";
}