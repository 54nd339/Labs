import java.util.Scanner;
class Student{
    String name, roll; int fm;
    float sm, cgpa;
    Scanner sc = new Scanner(System.in);
    Student(){
        System.out.print("Enter Name : ");
        name = sc.next();
        System.out.print("Enter roll : ");
        roll = sc.next();
        System.out.print("Enter full marks : ");
        fm = sc.nextInt();
        System.out.print("Enter secured marks : ");
        sm = sc.nextFloat();
        cgpa = (sm/fm)*10;
    }
    void display(){
        System.out.println("Name : "+name);
        System.out.println("Roll : "+roll);
        System.out.println("Secured Marks : "+sm);
        System.out.println("CGPA : "+cgpa);
    }
}
public class Q7{
    public static void main(String[] args){
        Student ob = new Student();
        ob.display();
    }
}