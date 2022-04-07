#include <iostream>
#include <cstring>
using namespace std;
int main(){
    string s, out;
    cin >> s;
    int count = 1;
    for(int i=0; i<s.length(); i++){
        if(s[i] == s[i+1]) count++;
        else{
            out += s[i]+to_string(count);
            count = 1;
        }
    }
    cout << out;
    return 0;
}