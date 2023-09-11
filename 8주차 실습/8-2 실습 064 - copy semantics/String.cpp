#include "String.h"
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

String::String(){
    s = new char[1];
    s[0] = '\0';
    len = 0;
}

String::String(const char* str){
    if(str){
        len = strlen(str);
        s = new char[len + 1];
        std::copy(str, str+len+1, s);

    }
    else{
        s = new char[1];
        s[0] = '\0';
        len=0;
    }
}

String::String(const String& str){
    s = new char[str.size() + 1];
    std::copy(str.s, str.s + str.size()+1, s);
    len = str.size();
}

String& String::operator=(const String& str){
    s = new char[str.size() + 1];
    std::copy(str.s, str.s + str.size()+1, s);
    len = str.size();
}

String::~String() {
    delete[] s;
}

const char* String::data() const{return s;}

char& String::at(size_t index){return s[index];}

size_t String::size() const{return len;}

void String::print(const char* str) const{cout << str << ": " << s << ", size: " << len << endl;}

void String::swap(String& str){}
