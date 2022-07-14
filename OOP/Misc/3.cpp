#include <iostream>
#include <vector>
using namespace std;
void print(vector<vector<int>> arr){
    for(int i = 0; i < arr.size(); i++)
        for(int j = 0; j < arr[0].size(); j++)
            cout << arr[i][j] << endl;
}

int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> A(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> A[i][j];

    vector<vector<int>> B(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> B[i][j];

    A.swap(B);
    print(A);

    vector<vector<int>> C(r, vector<int>(c, 0));
    for (int j = 0; j < B[0].size(); ++j) {
        for (int k = 0; k < A[0].size(); ++k) {
            for (int i = 0; i < A.size(); ++i) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    print(C);

    bool res = true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == j && C[i][j] != 1)
                res = false;
            else if (i != j && C[i][j] != 0)
                res = false;
        } 
    }
    cout << (res ? "IDENTITY MATRIX" : "NOT AN IDENTITY MATRIX") << endl;

    C.clear();
    cout << (C.empty() ? "1" : "0");
    return 0;
}