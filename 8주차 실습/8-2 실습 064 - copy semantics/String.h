#ifndef TEST_STRING_H
#define TEST_STRING_H

#include <stddef.h>
class String {
public:
    String();
    String(const char* str);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    const char* data() const;
    char& at(size_t index);
    size_t size() const;
    void print(const char* str="") const;
private:
    void swap(String& str);
    int len;
    char* s;
};


#endif //TEST_STRING_H
