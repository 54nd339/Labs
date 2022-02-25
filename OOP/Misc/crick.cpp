#include <iostream>
using namespace std;
class Cricketer{
    protected:
    string pname, pid;
    int n_match;
};
class Batsman : protected Cricketer{
    protected:
    int n_score;
};
class Bowler : protected Cricketer{
    protected:
    int n_wicket;
};
class All_rounder : protected Batsman, protected Bowler{
    float b_avg, wpm;
    public:
    All_rounder(){
        cin>>Batsman::pname>>Batsman::pid>>Batsman::n_match;
        cin>>n_score>>n_wicket;
        b_avg = (float)n_score/Batsman::n_match;
        wpm = (float)n_wicket/Batsman::n_match;
    }
    void print(){
        cout<< b_avg << " "<< wpm << endl;
    }
};
int main(){
    All_rounder obj;
    obj.print();
}