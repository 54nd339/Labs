#include <iostream>
using namespace std;
void test(){
    try {
        throw "hello";
    }
    catch (const char*) {
        cout << "Caught exception inside test\n";
        throw; //rethrow char* out of function
    }
}
int main() {
    cout << "Start" << endl;
    try {
        test();
    }
    catch(const char*){
        cout <<"Caught exception inside Main\n";
    }
    cout << "End" << endl;
    return 0;
}