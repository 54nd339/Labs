#include <iostream>
using namespace std;
class Book{
    public:
    string title, author;
    float price;
}b[3];
void get(){
    for(int i=0; i<3; i++){
        cout << "\nBook " << i+1 << " :\n";
        cout << "Title : ";
        cin >> b[i].title;
        printf("Author : ");
        cin >> b[i].author;
        printf("Price : ");
        cin >> b[i].price;
    }
}
void print(){
    cout << "\nsl.no.\tTitle\tAuthor\tPrice\n";
    for(int i=0; i<3; i++)
        cout << i << "\t" << b[i].title << "\t" << b[i].author << "\t" << b[i].price << "\n";
}
int main(){
    cout << "\nEnter Details :\n";
    get();
    cout << "\nEntered Details :\n";
    print(); 
    return 0;
}