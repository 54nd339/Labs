#include <iostream>
#include <string>
using namespace std;
class Account_Holder{
    string name, add, acc_type, email;
    long acc_no; float balance;
    public:
    Account_Holder(){
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter address : ";
        cin >> add;
        cout << "Enter account type : ";
        cin >> acc_type;
        cout << "Enter email : ";
        cin >> email;
        cout << "Enter account no. : ";
        cin >> acc_no;
        cout << "Enter balance : ";
        cin >> balance;
        this->check();
    }
    void check(){
        try{
            if (balance < 5000) throw 1;
        }
        catch(int x){
            cout << "Balance less than 5000, Please deposit.\n";
            this->deposit(); 
        }
        string s = email; bool flag = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '@'){
                flag = true; break;
            }
        }
        try{
            if(flag == false) throw 'a';
        }
        catch(char ch){
            cout <<"Email should've '@', Enter again : ";
            cin >> email; this->check();
        }
    }
    void deposit(){
        lab1:
        cout << "Enter amount to be deposited : ";
        int amount; cin >> amount;
        if (amount < 0){
            cout << "Negative amount not allowed.";
            goto lab1;
        }
        balance += amount; this->check();
    }
    void withdraw(){
        lab1:
        cout << "Enter amount to be withdrawn : ";
        int amount; cin >> amount;
        if (amount < 0){
            cout << "Negative amount not allowed.";
            goto lab1;
        }
        balance -= amount; this->check();
    }
    void print(){
        cout << "Balance : " << balance << endl;
    }
};
int main(){
    Account_Holder a; int ch;
    while(true){
        cout << "\n1. Deposit\n2. Withdraw\n3. Display\n0. Exit\n";
        cout << "Enter Your Choice : ";
        cin >> ch;
        if(ch == 1) a.deposit();
        else if(ch == 2) a.withdraw();
        else if(ch == 3) a.print();
        else if(ch == 0) break;
        else cout << "Wrong Input.";
    }
    return 0;
}