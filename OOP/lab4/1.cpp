#include<iostream>
using namespace std;
int n;
class book{
    string name, author;
    float price;
    public :
    void get(){
        cout << "\nEnter book name : ";
        cin >> name;
        cout << "Enter author name : ";
        cin >> author;
        cout << "Enter price : ";
        cin >> price;
    }
    void show(){
        cout << name << "\t" << author << "\t" << price << endl;
    }
    friend void range(book b[], float start, float end){
        int flag = 0;
        cout << "\nWithin the price range : \n";
        for(int i=0; i<n; i++){
            if(b[i].price >= start && b[i].price <= end){
                cout << b[i].name << " by " << b[i].author << " at " << b[i].price << endl;
                flag++;
            }
        }
        if(flag) cout << "\n" << flag << " books found.\n";
        else cout << "No Books Found.\n";
    }
}*b;

int main(){
    cout << "Enter no. of books : ";
    cin >> n;
    b = new book[n];
    for(int i=0; i<n; i++){
        cout << "\nInput " << i+1 << " : ";
        b[i].get();
    }
    cout << "\nDisplay :";
    cout << "\nNo.\tName\tAuthor\tPrice\n";
    for(int i=0; i<n; i++){
        cout << i+1 << "\t";
        b[i].show();
    }
    cout << "\nEnter start range : ";
    float start; cin >> start;
    cout << "Enter end range : ";
    float end; cin >> end;
    range(b, start, end);
    return 0;
}