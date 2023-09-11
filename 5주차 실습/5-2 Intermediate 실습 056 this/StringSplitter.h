#ifndef UNTITLED_STRINGSPLITTER_H
#define UNTITLED_STRINGSPLITTER_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>  //std::isalnum함수 쓰기 위해


class StringSplitter{
public:
    StringSplitter(std::string mystr);
    StringSplitter& trim();  //공백 제거 함수
    StringSplitter& removeNonAlnum();    //
    std::vector<std::string> split(char delim);    //delim을 기준으로 분해
private:
    std::string myString;
};

#endif //UNTITLED_STRINGSPLITTER_H
