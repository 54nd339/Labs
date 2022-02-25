#include <iostream>
#include <fstream>
using namespace std;
int main () {
    char data[100];
    ofstream out;
    out.open("file1.txt");
    cout << "Enter your name: ";
    cin.getline(data, 100);
    out << data << endl;
    cout << "Enter your age: "; cin >> data;
    cin.ignore();
    out << data << endl;
    out.close();
    
    ifstream infile;
    infile.open("file1.txt");
    cout << "Reading from a file : " << endl; infile >> data;
    cout << data << endl; infile >> data;
    cout << data << endl;
    infile.close();
    return 0;
}