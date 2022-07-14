#include<iostream>
#include<cmath>
using namespace std;
class Polar {
    float r, a;
    Polar calc (Polar A, Polar B, int flag) {
        float rad1 = A.a * (3.14 / 180);
        float x1 = A.r * cos(rad1);
        float y1 = A.r * sin(rad1);
        //cout << "1 : " << x1 << " " << y1 << endl;
        float rad2 = B.a * (3.14 / 180);
        float x2 = B.r * cos(rad2);
        float y2 = B.r * sin(rad2);
        //cout << "2 : " << x2 << " " << y2 << endl;
        float resx = x1 + flag*x2;
        float resy = y1 + flag*y2;
        //cout << "r r : " << resx << " " << resy << endl;
        float resr = sqrt(resx*resx + resy*resy);
        float resa = atan(resy/resx) * (180/3.14);
        //cout << "r p : " << resr << " " << resy << endl;
        return Polar(resr, resa);
    }

    public :
    Polar(float r=0, float a=0) {
        this->r = r; this->a = a;
    }
    Polar operator +(Polar &obj) {
        return calc(*this, obj, 1);
    }
    Polar operator -(Polar &obj) {
        return calc(*this, obj, -1);
    }
    void print() {
        cout << r << endl;
        cout << a << endl;
    }
};

int main() {
    float r1, a1; cin >> r1 >> a1;
    Polar p1(r1, a1);

    float r2, a2; cin >> r2 >> a2;
    Polar p2(r2, a2);

    int ch; cin >> ch;

    switch(ch) {
        case 1:
            (p1+p2).print();
            break;
        case 2:
            (p1-p2).print();
            break;
        default:
            cout << "Invalid Input";
    }
    return 0;
}