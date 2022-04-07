#include<iostream>
using namespace std;
int main(){
    cout << "Enter array size : ";
    int n; cin >> n;
    int *ar = new int[n];
    cout << "Enter array Elements : ";
    for(int i=0; i<n; i++)
        cin >> ar[i];
    try{
        int ind;
        cout << "Enter an index : ";
        cin >> ind;
        if(ind < 0)
            throw 0; 
        else if(ind>=n)
            throw 'a';
        else
            cout << ar[ind];
    }
    catch(char c) {
        cout << "Index out of bound exception. ";
    }
    catch(int i) {
        cout << "Negative index exception. ";
    }
    catch(...)  {
        cout << "Default exception";
    }
}