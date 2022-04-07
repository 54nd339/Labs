import java.util.Scanner;
class Rectangle{
    float length, breadth;
    Scanner sc = new Scanner(System.in);
    Rectangle(){
        System.out.print("Enter length and breadth of the rectangle : ");
        length = sc.nextFloat();
        breadth = sc.nextFloat();
    }
    void area(){
        System.out.println("Area : "+ (length*breadth));
    }
    void perimeter(){
        System.out.println("Perimeter : "+ (2*(length+breadth)));
    }
}
public class Q6 {
    public static void main(String[] args) {
        Rectangle ob = new Rectangle();
        ob.area(); ob.perimeter();
    }
}