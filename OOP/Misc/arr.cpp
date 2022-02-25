#include<iostream>
using namespace std;
class Arr{
    int *arr, n;
    public:
    Arr(int n=0){
        this->n = n;
        arr=new int[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
    }
    Arr join(Arr obj){
        Arr res; int i,j;
        res.n = this->n + obj.n;
        res.arr=new int[n];
        for(i = 0; i<this->n; i++)
            res.arr[i] = arr[i];
        for(j = 0; j<obj.n; j++)
            res.arr[i+j] = obj.arr[j];
        return res;
    }
    void display(){
        for(int i = 0; i<n; i++)
            cout << arr[i] << " ";
    }
};
int main(){
    Arr ar1(5), ar2(6);
    Arr res = ar1.join(ar2);
    res.display();
    return 0;
}
