#include<iostream>
using namespace std;
class Book{
    protected:
    string title, author;
    float price;
    Book(){
        cout<<"Enter Title, author, price : ";
        cin>>title>>author>>price;
    }
    void display(){
        cout<<"Title : "<<title<<endl;
        cout<<"Author : "<<author<<endl;
        cout<<"price : "<<price<<endl;
    }
};
class Print_Book: protected Book{
    int n_pages;
    public :
    Print_Book(){
        cout<<"Enter No. of pages : ";
        cin>>n_pages;
    }
    void display(){
        Book::display();
        cout<<"No. of Pages : "<<n_pages<<endl;
    }
};
class E_Book: protected Book{
    int sizes;
    public :
    E_Book(){
        cout<<"Enter Size : ";
        cin>>sizes;
    }
    void display(){
        Book::display();
        cout<<"Size : "<<sizes<<endl;
    }
};
int main(){
    E_Book eb[2];
    Print_Book pb[3];
    for(int i=0; i<2;i++)
        eb[i].display();
    for(int i=0; i<3; i++)
        pb[i].display();
    return 0;
}