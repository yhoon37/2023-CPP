#include "Stack.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    switch(n){
        case 1 :
            try {
                Stack<char> stack(1);
                stack.push('a');
                stack.pop();
                stack.pop();
                stack.print();
            } catch(StackException& e){
                cerr << e.what() << endl;
            }
            break;
        case 2 :
            try {
                Stack<char> stack (1);
                stack.push('a');
                stack.push('b');
                stack.print();
            } catch(StackException& e){
                cerr << e.what() << endl;
            }
            break;
        case 3 :
            try {
                Stack<int> stack(1);
                stack.push(1);
                stack.pop();
                stack.push(2);
                stack.print();      // 2 출력됨
                stack.pop();
            } catch(StackException& e){
                cerr << e.what() << endl;
            }
            break;
        case 4 :
            try {
                Stack<int> stack(2);
                stack.push(1); stack.push(2);
                stack.pop();    stack.pop();
                stack.push(3);
                stack.print();    // 3 출력됨
            } catch(StackException& e){
                cerr << e.what() << endl;
            }
            break;
    }
    return 0;
}
