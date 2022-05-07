package General;
import java.util.*;
public class Employee {
    protected String empid;
    private String ename;

    public Employee(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter EmpID : ");
        empid = sc.next();
        System.out.print("Enter EmpName : ");
        ename = sc.next();
    }
    public float earning(float basic){
        float earn = 1.95f * basic;
        return earn;
    }
}