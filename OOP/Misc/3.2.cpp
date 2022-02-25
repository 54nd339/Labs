#include <iostream>
using namespace std;
bool check(string s){
    int x = int(s[0]);
    if (!((x >= 65 && x < 90) || (x >= 97 && x <= 122)))
        throw 'a';
    
    int l = s.length();
    int start = l-4, end = l-1;
    if(s.substr(start,end) != ".com")
        throw 0;
    
    bool flag = true;
    for (int i=0; i<l; i++){
        if(s[i]=='@'){
            flag = false; break;
        }
    }
    if(flag) throw 0.0;
    return true;
}
int main(){
    cout << "Enter a mail id : ";
    string email; cin >> email;
    try {
        if(check(email))
            cout << "Valid mail" << endl;
    }
    catch(char c) {
        cout << "mail id must begin with an alphabet" << endl;
    }
    catch(int x){
        cout << "mail id must be \".com\" at the end of the ID" << endl;
    }
    catch(double x){
        cout << "mail id should've one special \"@\"" << endl;
    }
    catch(...){
        cout << "default exception" << endl;
    }
}