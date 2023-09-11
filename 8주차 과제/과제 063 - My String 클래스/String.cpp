#include "String.h"
#include <cstring>
#include <algorithm>

using namespace std;
int String:: count_=0;

String::String(){
     data_ = new char[1];
    data_[0] = '\0';
     len_ = 0;
    String::count_++;
    cout << "Default Constructor" << endl;
    cout << "# of String object: " << String::count_  << endl;
}
String::String(const char* s){
    if(s){
         this ->len_ = strlen(s);
        data_ = new char[len_ + 1];
        std::copy(s, s+ len_ +1, data_);
    }
    else{
        data_ = new char[1];
        data_[0] = '\0';
        len_=0;
    }
    String::count_++;
    cout << "Constructor" << endl;
    cout << "# of String object: " << String::count_  << endl;
}
String::~String() noexcept{
    delete[] data_;
    String::count_--;
    cout << "Destructor" << endl;
    cout << "# of String object: " << String::count_ << endl;
}
String::String(const String& s) noexcept{
     this -> len_ = s.size();
    data_ = new char[len_ + 1];
    std::copy(s.data(), s.data()+len_+1, data_);

    String::count_++;
    cout << "Copy Constructor" << endl;
    cout << "# of String object: " << String::count_  << endl;
}

const char* String::data() const{return data_;}
bool String::empty() const{return len_==0;}
size_t String::size() const{return len_;}
String& String::append(const String& str){
    char* temp = data_;

     this->data_ = new char[len_+str.size()+1];
    std::copy(temp, temp+len_, data_);
    std::copy(str.data(), str.data()+str.size()+1, data_+len_);
    len_ += str.size();
    delete[] temp;
}
String& String::append(const char* str){
    char* temp = data_;
    data_ = new char[len_+strlen(str)+1];
    std::copy(temp, temp+len_, data_);
    std::copy(str, str+strlen(str)+1, data_+len_);
    cout << data_;
    len_ += strlen(str);
    delete[] temp;
}