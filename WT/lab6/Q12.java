import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class Account{
    static int c = 0;
    long acc_no; float bal;
    Account(){
        System.out.println("\nEnter details of Person "+(++c));
        System.out.print("Enter Account No. : ");
        acc_no = Input.sc.nextLong();
        System.out.print("Enter Balance : ");
        bal = Input.sc.nextFloat();
    }
    void display(){
        System.out.println("Account No. : "+acc_no);
        System.out.println("Balance : "+bal);
    }
}
class Person extends Account{
    static int n = 0;
    String name, aadhar;
    Person(){
        System.out.print("Enter Name : ");
        name = Input.sc.next();
        System.out.print("Enter Aadhar : ");
        aadhar = Input.sc.next();
    }
    @Override
    void display(){
        System.out.println("\nDetails of Person "+(++n));
        System.out.println("Name : "+acc_no);
        System.out.println("Aadhar : "+aadhar);
        super.display();
    }
}
public class Q12{
    public static void main(String[] args){
        Person ob[] = new Person[5];
        for(int i=0; i<5; i++)
            ob[i] = new Person();
        for(int i=0; i<5; i++)
            ob[i].display();
    }
}