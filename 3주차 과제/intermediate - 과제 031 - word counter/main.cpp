#include <iostream>
#include <map>
#include <regex>
#include <vector>
#include <algorithm>

bool compare(std::pair<std::string, int>a, std::pair<std::string, int>b){
    bool result = 0;
    if(a.second > b.second) result = true;
    else if((a.second == b.second) && (a.first < b.first)) result = true;
    return result;
}

std::map<std::string, int> make_word(void){
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
    return words;
}

void top5(std::map<std::string, int>& words){
    std::vector<std::pair<std::string, int>> words_vector(words.begin(), words.end());//오호

    std::sort(words_vector.begin(), words_vector.end(), compare);

    std::cout << "#Words: " << words.size() << std::endl;
    std::cout << "Top 5 Word Frequencies" << std::endl;
    std::for_each(words_vector.begin(), words_vector.begin()+5, [&words_vector](auto &w){
        std::cout << std::find(words_vector.begin(), words_vector.end(), w) - words_vector.begin() + 1 << " " << w.first << ": " << w.second << std::endl;
    });
}

void find_word(std::map<std::string, int>& words){
    std::string str;
    std::cout << "Find Word Frequencies" << std::endl;

    while(std::cin >> str && str != "QUIT"){
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(words.find(str) != words.end()){
            std::cout << str << ": " << words[str] << std::endl;
        }
        else{
            std::cout << str << ": 0" <<std::endl;
        }
    }
    std::cout << std::endl << "Bye!";
}

int main() {
    std::map<std::string, int> words = make_word();
    top5(words);
    find_word(words);

    return 0;
}
