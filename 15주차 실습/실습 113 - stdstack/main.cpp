#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<int> s;
    int n;
    cin >> n;

    for(int i=0; i < n; i++){
        string cmd;
        int num;
        cin >> cmd;

        if(cmd == "push") {
            cin >> num;
            s.push(num);
        }
        else if (cmd == "pop"){
            if(s.empty()){
                cout << -1 << endl;
            }
            else{
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (cmd == "size"){
            cout << s.size() << endl;
        }
        else if (cmd == "empty"){
            cout << s.empty() << endl;
        }

    }

    return 0;
}