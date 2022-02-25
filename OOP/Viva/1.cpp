#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("file.txt");
    char ch;
    fin.seekg(5,ios::beg); fin.seekg(5,ios::cur);
    fin.get(ch);
    cout << ch;
    fin.close(); //closing file
    return 0;
}