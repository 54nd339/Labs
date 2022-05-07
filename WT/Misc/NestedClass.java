import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class Stud1{
    int marks;
    Stud1(){
        System.out.print("Enter Avg of stud 1 : ");
        marks = Input.sc.nextInt();
    }
    class Stud2{
        int marks;
        Stud2(){
            System.out.print("Enter Avg of stud 2 : ");
            marks = Input.sc.nextInt();
        }
    }
    void display(){
        Stud2 ob = new Stud2();
        if(marks > ob.marks)
            System.out.println("Avg of Stud 1 : "+marks);
        else
            System.out.println("Avg of Stud 2 : "+ob.marks);
    }
}
public class NestedClass {
    public static void main(String[] args) {
        Stud1 ob = new Stud1();
        ob.display();
    }
}