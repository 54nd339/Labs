#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Count {
    int size; T *arr;
    public:
    Count(int n) {
        size = n;
        arr = new T[n];
        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }
    void countFrequency() {
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++) {
            if (visited[i] == true)
                continue;
     
            int count = 1;
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    visited[j] = true;
                    count++;
                }
            }
            cout << arr[i] << "-" << count << endl;
        }
    }
};
int main() {
    int n; cin >> n;
    Count<int> dc_int(n);
    dc_int.countFrequency();

    cin >> n;
    Count<float> dc_float(n);
    dc_float.countFrequency();
    return 0;
}