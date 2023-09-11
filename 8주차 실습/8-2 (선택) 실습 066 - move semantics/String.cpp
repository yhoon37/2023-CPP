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
        std::copy(str, str+len+1, s); //맞나?

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
    return *this;
}

String::String(String&& str) noexcept{
//    s = new char[str.size()+1];
//    std::copy(str.s, str.s + str.size()+1, s);
//    len = str.size();
//
//    delete[] str.s;
//    str.s = new char[1];
//    str.s[0] = '\0';
//    str.len = 0;

    s = new char[1];
    s[0] = '\0';
    len = 0;
    swap(str);
}

String& String::operator=(String &&str) noexcept {
//    s = new char[str.size()+1];
//    std::copy(str.s, str.s + str.size()+1, s);
//    len = str.size();
//
//    delete[] str.s;
//    str.s = new char[1];
//    str.s[0] = '\0';
//    str.len = 0;
    if(this == &str) return *this;
    s = new char[1];
    s[0] = '\0';
    len = 0;
    str.swap(*this);
    return *this;
}


String::~String(){
    if(s) delete[] s;
}

const char* String::data() const{return s;}

char& String::at(size_t pos){
    if(len!=0 && 0 <= pos && pos < len)
        return s[pos];
    throw std::out_of_range("out of range at index: " + std::to_string(pos) + ", but the length of String is " + std::to_string(len));
}

size_t String::size() const{return len;}

void String::print(const char* str) const{cout << str << ": " << s << ", size: " << len << endl;}

void String::swap(String& str){
    using std::swap;
    swap(s, str.s);
    swap(len, str.len);
}
