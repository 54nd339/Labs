#include <iostream>
using namespace std;

template <class T>
class Array{
    T *arr; int n;
    public :
    Array() {
        cout << "\nEnter Size of the array : ";
        cin >> n;
        arr = new T[n];
        cout << "Enter array elements : ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }
    void sort() {
        for (int i = 0; i < n - 1; i++)
            for (int j = n - 1; i < j; j--)
                if (arr[j] < arr[j - 1])
                    swap(arr[j], arr[j - 1]);
    }
    void print() {
        for (int i = 0; i < n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};
  
int main() {
    Array <int>a;
    a.sort(); a.print();
    
    Array <float>A;
    A.sort(); A.print();
  
    return 0;
}