#include <iostream>
using namespace std;

template <typename T>
T *input(int n) {
    T *ar = new T[n];
    cout << "Enter array elemnts : ";
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    return ar;
}

template <typename T>
void sort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
              swap(a[j], a[j - 1]);
}

template <typename T>
void print(T a[], int n) {
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    cout << "Enter Size of the array : ";
    int n; cin >> n;
    int *ar = new int[n];
    ar = input<int>(n);
    sort<int>(ar, n);
    print<int>(ar, n);

    float *arr = new float[n];
    arr = input<float>(n);
    sort<float>(arr, n);
    print<float>(arr, n);
    
    return 0;
}