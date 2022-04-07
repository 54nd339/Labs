#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string out = "";
    ifstream in;
    in.open("file1.txt", ios::in);
    in.seekg(0, ios::end);
    int len = in.tellg();
    char ch;
    while(len--){
        in.seekg(len, ios::beg);
        in.get(ch);
        if(ch == ' ') break;
        out = ch + out;
    }
    cout << out;
    return 0;
}