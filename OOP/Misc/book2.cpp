#include<iostream>
using namespace std;
class Book{
    public:
    string title, author;
    int no;
    float price;
    Book(){
        cout << "Enter title, author, price, copies available : ";
        cin >> title >> author >> price >> no;
    }
    void display(){
        cout << "Author : " << author << endl;
        cout << "price : " << price << endl;
        cout << "Copies Available : " << no << endl;
    }
    void update(){
        cout << "\nEnter new price : ";
        cin >> price;
        cout << "Enter no. of copies : ";
        cin >> no;
    }
    void sell(){
        int n;
        cout << "\nEnter no. of copies : ";
        cin >> n;
        if(no<n) cout << "Copies Available : " << no << endl;
        else{
            no-=n;
            cout << "Total Price : " << n*price << endl;
        }
    }
};
int main(){
    Book b[2]; string name; int ch;
    cout << "1. Update \n2. Buy \n0. Exit";
    while(true){
        cout << "\nEnter option : ";
        cin >> ch;
        if(ch == 0) break;
        cout << "Enter name : ";
        cin >> name;
        int flag = 1;
        for(int j=0; j<2; j++){
            if(b[j].title == name){
                if(ch == 1) b[j].update();
                else if(ch == 2) b[j].sell();
                flag = 0;
            }
        }
        if(flag) cout << "Book not available\n";
    }
    return 0;
}