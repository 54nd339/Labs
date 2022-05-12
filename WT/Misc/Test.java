import java.util.*;
class Input{
    static Scanner sc = new Scanner(System.in);
}
abstract class Organization{
    static String name; static int year;
    static void in(){
        System.out.print("\nEnter Name of the Organization : ");
        name = Input.sc.next();
        System.out.print("Enter year of Organization : ");
        year = Input.sc.nextInt();
    }
    static void show(){
        System.out.println("\nName of the organization : "+name);
        System.out.println("Year : "+year);
    }
    abstract void display();
}
class Employee extends Organization{
    String ename, desg;
    int age; float salary;
    Employee(){
        System.out.print("\nEnter Name of the employee : ");
        ename = Input.sc.next();
        System.out.print("Enter designation : ");
        desg = Input.sc.next();
        System.out.print("Enter age of the employee : ");
        age = Input.sc.nextInt();
        System.out.print("Enter salary of the employee : ");
        salary = Input.sc.nextFloat();
    }
    void display(){
        System.out.println("\nName of the employee : "+ename);
        System.out.println("Designation : "+desg);
        System.out.println("Age of the employee : "+age);
        System.out.println("Salary of the employee : "+salary);
    }
}
class Department extends Organization{
    String dname, did;
    Department(){
        System.out.print("Enter Name of the dept : ");
        dname = Input.sc.next();
        System.out.print("Enter dept ID : ");
        did = Input.sc.next();
    }
    void display(){
        System.out.println("Name of the department : "+dname);
        System.out.println("Department ID : "+did);
    }
}
class A{
    Organization d, e;
    A(){
        e = new Employee();
        d = new Department();
    }
    void display(){
        e.display();
        d.display();
    }
}
public class Test{
    public static void main(String[] args){
        Organization.in();
        A a[] = new A[2];
        a[0] = new A();
        a[1] = new A();
        Organization.show();
        a[0].display();
        a[1].display();
    }
}