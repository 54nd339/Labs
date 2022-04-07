#include <iostream>
using namespace std;
class Array {
    int *arr;
    public:
    int size;
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
};
  
int main(){
    Array arr;
    int sum = 0;
    for (int i = 0; i < arr.size; i++)
        sum += arr[i];
    float avg = sum/arr.size;
    cout << "sum : " << sum << endl;
    cout << "avg : " << avg << endl;
    return 0;
}