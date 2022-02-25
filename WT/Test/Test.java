import java.util.*;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class BankAccount{
    long acc_no; String name; double bal;
    static String mname; static double mbal=0;
    BankAccount(){
        System.out.print("\nEnter Account No. : ");
        acc_no = Input.sc.nextLong();
        System.out.print("Enter Name : ");
        name = Input.sc.next();
        System.out.print("Enter Balance : ");
        bal = Input.sc.nextDouble();
        if(mbal < bal){
            mname = name;
            mbal = bal;
        }
    }
    void display(){}
}
class Display extends BankAccount{
    void display(){
        System.out.println("\nAccount No. : "+acc_no);
        System.out.println("Name : "+name);
        System.out.println("Balance : "+bal);
    }
}
public class Test{
    public static void main(String[] args){
        BankAccount ob1 = new Display();
        BankAccount ob2 = new Display();
        ob1.display();
        ob2.display();
        System.out.println("\nPerson with max balance : "+BankAccount.mname);
    }
}