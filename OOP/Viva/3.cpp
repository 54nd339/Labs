#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main() {
    ifstream fin("file.txt"); 
    int start,end,p,q; char ch;
    //cout << "Enter starting and ending position : ";
    //cin >> start >> end;
    if(fin) {
        fin.seekg(end);
        int end = fin.tellg();
        fin.seekg(start);
        int begin = fin.tellg();
        char *out = new char [end-begin];
        fin.read(out, end-begin);
        fin.close();
        cout.write(out, strlen(out));
        delete []out;
    }
    return 0;
}