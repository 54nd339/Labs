import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class Shape{
    double area;
    void showArea(){
        System.out.println("Area : "+area);
    }
}
class Rectangle extends Shape{
    float l, b;
    Rectangle(){
        System.out.print("Enter length and breadth of rectangle : ");
        l = Input.sc.nextFloat();
        b = Input.sc.nextFloat();
    }
    void calculate(){
        area = l*b; this.showArea();
    }
}
class Circle extends Shape{
    float r;
    Circle(){
        System.out.print("Enter radius of circle : ");
        r = Input.sc.nextFloat();
    }
    void calculate(){
        area = 3.14*r*r;
        this.showArea();
    }
}
public class Q11 {
    public static void main(String[] args) {
        Rectangle r = new Rectangle();
        r.calculate();
        Circle c = new Circle();
        c.calculate();
    }
}