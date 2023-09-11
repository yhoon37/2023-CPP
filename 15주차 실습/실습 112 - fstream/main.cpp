#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // ifstream, ofstream 은 자동으로 연 파일을 닫는다.
    try {
        ifstream fin;
        fin.exceptions(ios_base::failbit | ios_base::badbit);
        fin.open("config.ini");     //default   is   ios_base::in
    } catch(const std::ios_base::failure& e){
        cerr << e.what() << endl;
    }

    try {
        ofstream fout;
        fout.exceptions(ios_base::failbit | ios_base::badbit);
        fout.open("config/config.ini");    //default   is   ios_base::out
        fout << "This is an example for the exception in C++!" << endl;
    } catch(const std::ios_base::failure& e){
        cerr << e.what() << endl;
    }

    return 0;
}