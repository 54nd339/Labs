import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
abstract class Student {
    int roll; String reg;
    abstract void course();
}
class Kiitian extends Student {
    String course;
    Kiitian(){
        System.out.print("Enter Roll No. : ");
        roll = Input.sc.nextInt();
        System.out.print("Enter Registration No. : ");
        reg = Input.sc.next();
    }
    void course(){
        System.out.print("Enter Course : ");
        course = Input.sc.next();
    }
    void display(){
        System.out.println("\nRoll : "+roll);
        System.out.println("Registration No. : "+reg);
        System.out.println("Course : "+course);
    }
}
public class Q1 {
    public static void main(String[] args) {
        Kiitian ob = new Kiitian();
        ob.course(); ob.display();
    }
}