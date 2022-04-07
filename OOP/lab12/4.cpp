#include <iostream>
#include <string.h>
using namespace std;
class str {
    char *s;
    public:
    str(string st = ""){
        s = new char[st.length()];
        strcpy(s , st.c_str());
	}
    str operator +(str st){
		str result;
        int l = sizeof(st.s)+sizeof(this->s);
        result.s = new char[l];
        strcpy(result.s, this->s);
        strcat(result.s, st.s);
        return result;
	}
    void print(){
        cout << s << endl;
    }
};

int main(){
    string s1, s2;
    printf("Enter 2 strings : ");
    cin >> s1 >> s2;
	str str1 = s1, str2 = s2;
    str str3 = str1 + str2;
    str3.print();
	return 0;
}