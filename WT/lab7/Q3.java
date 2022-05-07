import java.util.*;
class Input{
    static Scanner sc = new Scanner(System.in);
}
interface Salary {
    void earning();
    void deductions();
    void bonus();
}
abstract class Manager implements Salary {
    public void earning(){}
    public void deductions(){}
}
class Substaff extends Manager {
    float basic, earn, deduct, bon;
    Substaff(){
        System.out.print("Enter Basic Salary : ");
        basic = Input.sc.nextFloat();
    }
    public void earning(){
        earn = 1.95f * basic;
        System.out.println("Basic : "+basic);
        System.out.println("DA : "+(0.8f*basic));
        System.out.println("HRA : "+(0.15f*basic));
        System.out.println("Earning : "+earn);
    }
    public void deductions(){
        deduct = 0.12f * basic;
        System.out.println("Deduction PF : "+deduct);
    }
    public void bonus(){
        bon = 0.5f * basic;
        System.out.println("Bonus : "+bon);
    }
}
public class Q3 {
    public static void main(String[] args) {
        Substaff ob = new Substaff();
        ob.earning();
        ob.deductions();
        ob.bonus();
    }
}