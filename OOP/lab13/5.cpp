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
        if(ind < 0 || ind>=n)
            throw 0;
        else
            cout << "Element : " << ar[ind];
    }
    catch(int k) {
        cout << "Index out of bound exception. ";
    }
}