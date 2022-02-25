#include <iostream>
using namespace std;
class Array {
    int *arr, size;
    public:
    Array(){
        cout << "Enter Size of the array : ";
        cin >> size;
        arr = NULL;
        if (size != 0) {
            arr = new int[size];
            cout << "Enter array Elements : ";
            for (int i = 0; i < size; i++)
                cin >> arr[i];
        }
    }
  
    int& operator[](int index){
        if (index >= size) {
            cout << "Array index out of bound, exiting";
            exit(0);
        }
        return arr[index];
    }
  
    void print(){
        cout << "Array : ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
  
int main(){
    Array arr;
    int ind, inp;
    cout << "Enter the index and the new data : ";
    cin >> ind >> inp;
    arr[ind] = inp;
    arr.print();
    return 0;
}