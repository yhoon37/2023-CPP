#ifndef STACKEXCEPTION_STACK_H
#define STACKEXCEPTION_STACK_H

#include "StackException.h"
#include <iostream>

template<typename T>
class Stack {
public:
    Stack(int sz): size(sz), s(new T[size]){}      //객체 초기화 및 필요한 자원을 획득하시오
    ~Stack() noexcept {delete[] s;}             //사용한 자원을 해제하시오
    Stack(Stack&) = delete;// 복사 생성자와 복사 대입 연산자를 삭제하시오
    Stack operator = (Stack&) = delete;
    void push(T c) { //예외 발생 시 StackException 던지시오
        if(top >= size){
            throw StackException("Stack is full!", __FILE__, __LINE__);
        }
        else{
            s[top++] = c;
        }
    }
    T pop() {   //예외 발생 시 StackException 던지시오
        if(top <= 0){
            throw StackException("Stack is empty", __FILE__, __LINE__);
        }
        else{
            T r = s[--top];
            return r ;
        }
    }
    void print() const {
        for(int i=0; i<top; i++)
            std::cout << s[i] << std::endl;
    }     //스택의 모든 원소를 '\n' 으로 구분하여 출력하시오

private:
    int size = 0;   int top = 0;
    T* s = nullptr;
} ;

#endif //STACKEXCEPTION_STACK_H
