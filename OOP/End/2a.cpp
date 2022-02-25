#include <iostream>
#include <cmath>
using namespace std;
class Triangle{
    protected:
    float area;
    public:
    void display(){
        cout << "Area : " << area << endl;
    }
    virtual void calcArea() = 0;
};
class equilateral : public Triangle{
    float a;
    public:
    equilateral(){
        cout << "Enter Side of the triangle : ";
        cin >> a;
    }
    virtual void calcArea() {
        area = 0.433 * a * a;
    }
};
class isoscele : public Triangle{
    float b, h;
    public:
    isoscele(){
        cout << "Enter breadth and height of the triangle : ";
        cin >> b >> h;
    }
    virtual void calcArea() {
        area = 0.5 * b * h;
    }
};
class scalene : public Triangle{
    float a, b, c;
    public:
    scalene(){
        cout << "Enter Sides of the triangle : ";
        cin >> a >> b >> c;
    }
    virtual void calcArea() {
        float s = (a + b + c) / 3.0;
        area = sqrt(s * (s-a) * (s-b) * (s-c));
    }
};
int main(){
    equilateral e; e.calcArea(); e.display();
    scalene s; s.calcArea(); s.display();
    isoscele i; i.calcArea(); i.display(); 
}