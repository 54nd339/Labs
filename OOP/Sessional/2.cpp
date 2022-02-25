//20051025 Sandeep
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string out = "", s;
    ofstream ofs;
    ofs.open("file.txt", ios::out);
    cout << "Enter A String : ";
    getline(cin, s); ofs << s;
    int len = ofs.tellp();
    ofs.close();

    ifstream in; char ch;
    in.open("file.txt", ios::in);
    in.seekg(0, ios::end);
    int count = 0;
    while(len--){
        in.seekg(len, ios::beg);
        in.get(ch);
        if(ch==' ') break;
        ch = (char)toupper(ch);
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            count++;
    }
    in.close();
    cout << "Vowel count in last word : " << count << endl;
    return 0;
}