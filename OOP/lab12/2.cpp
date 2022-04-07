#include <iostream>
using namespace std;
class Array {
    int n, *arr;
    public:
    friend istream &operator>>(istream  &input, Array &a) {
        printf("Enter size of array : ");
        input >> a.n;
        printf("Enter array elements : ");
        a.arr = new int[a.n];
        for (int i = 0; i < a.n; i++)
            input >> a.arr[i];
        return input;            
    }
    friend ostream &operator<<(ostream &output, const Array &a) {
        printf("Array Elements : ");
        for (int i = 0; i < a.n; i++)
            output << a.arr[i] << " ";
        return output;
    }    
};

int main() {
    Array a;
    cin >> a; cout << a << endl;
    return 0;
}