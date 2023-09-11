#include "StringSplitter.h"

bool isNotAlNum(char ch){
    bool result = true;
    if(std::isalnum(ch)){
        result = false;
    }
    else if(ch == ' '){
        result = false;
    }
    return result;
}

StringSplitter::StringSplitter(std::string myString) {this->myString = myString;}

StringSplitter& StringSplitter::trim() {
    auto a = std::find_if(myString.begin(), myString.end(), [](auto it){return it != ' ';});
    (this->myString).erase(std::remove(myString.begin(), myString.end(), '\n'), myString.end());
    //줄바꿈 문자 제거
    (this->myString).erase(myString.begin(), a);
    //공백이 아닌 문자 부터 시작
    return *this;
}

StringSplitter& StringSplitter::removeNonAlnum() {
    (this->myString).erase(std::remove_if(myString.begin(), myString.end(), isNotAlNum), myString.end());
    return *this;
}

std::vector<std::string> StringSplitter::split(char delim) {
    std::vector<std::string> tokens;
    for(auto ch = (this->myString).begin(); ch <= (this->myString).end(); ch++){
        static auto first = ch;
        if(*ch == delim || ch == (this->myString).end()){
            auto last = ch;
            std::string word{first, last};
            first = last+1;
            tokens.push_back(word);
        }
    }
    return tokens;
}