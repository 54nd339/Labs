#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string s; char ch;
    ofstream ofs;
    ofs.open("file1.txt", ios::out);
    getline(cin, s);
    ofs << s;
    int len = ofs.tellp();
    ofs.close();

    ifstream in;
    in.open("file1.txt", ios::in);
    ofs.open("file2.txt", ios::out);
    while(len--) {
        in.seekg(len, ios::beg);
        in.get(ch);
        cout << ch << endl; //TEST
        ofs.put(ch);
    }
    return 0;
}