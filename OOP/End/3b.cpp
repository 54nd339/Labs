#include <iostream>
using namespace std;
class Time{
    int h, m, s;
    public:
    Time(int a=0, int b=0, int c=0){
        h = a; m = b; s = c;
    }
    friend bool operator >(Time &end, Time &start){
        if(end.h > start.h)
            return true;
        else{
            if(end.m > start.m)
                return true;
            else{
                if(end.s > start.s)
                    return true;
                else
                    return false;
            }
        }
    }
    friend void display(Time &start, Time &end){
        int hour = end.h - start.h;
        int min = end.m - start.m;
        int sec = end.s - start.s;
        if (min < 0) {
            hour--; min+=60;
        }
        if(sec < 0) {
            min--; sec+=60;
        }
        cout << "Time taken : " << hour << ":" << min << ":" << sec;
    }
};
int main(){
    Time start(4, 10, 15), end(5, 9, 10);
    try{
        if(end > start) display(start, end);
        else throw 1;
    }
    catch (int m){
        cout << "Wrong Input\n";
    }
    return 0;
}