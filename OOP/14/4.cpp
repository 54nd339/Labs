//20051025 Sandeep
#include <iostream>
using namespace std;
bool check(string s){
    if(s.length()!=10)
        throw 'a';

    bool flag = true;
    for(int i=0; i<s.length(); i++) {
        int x = int(s[i]);
        if(!(x>=48 && x<=57)){
            flag = false; break;
        }
    }
    if(!flag) throw 0;
    
    if(s[0]=='0') throw 0.0;
    
    if (s.substr(5,9) == "00000")
        throw true;

    return true;
}
int main(){
    cout << "Enter the phone no. : ";
    string phone; cin >> phone;
    try {
        if(check(phone))
            cout << "Valid Phone NO." << endl;
    }
    catch(char c) {
        cout << "Phone no. should have 10 digits." << endl;
    }
    catch(int x){
        cout << "only no. between 0 and 9 are accepted." << endl;
    }
    catch(double x){
        cout << "First digit can't be 0" << endl;
    }
    catch(bool x){
        cout << "last 5 digits can't be 0" << endl;
    }
    catch(...){
        cout << "default exception" << endl;
    }
}