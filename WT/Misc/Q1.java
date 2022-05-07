import java.util.*;
class Input{
    static Scanner sc = new Scanner(System.in);
}
interface Bank {
    void deposit();
    void withdraw();
    void details();
}
class SBI implements Bank{
    float amount; String accno;
    SBI(){
        System.out.print("\nEnter Account Number : ");
        accno = Input.sc.next();
        System.out.print("Enter Amount : ");
        amount = Input.sc.nextFloat();
    }

    @Override
    public void deposit(){
        System.out.print("\nEnter Amount to be deposited : ");
        float a = Input.sc.nextFloat();
        System.out.println("Old amount : "+this.amount+"\nNew amount : "+(this.amount+a));
        this.amount += a;
    }
      
    @Override
    public void withdraw(){
        System.out.print("\nEnter Amount to be withdrawn : ");
        float a = Input.sc.nextFloat();
        System.out.println("Old amount : "+this.amount+"\nNew amount : "+(this.amount-a));
        this.amount -= a;
    }
      
    @Override
    public void details(){
        System.out.println("\nDetails : ");
        System.out.println("Account No. : "+this.accno);
        System.out.println("Amount : "+this.amount);
    }
}
  
class HDFC implements Bank{
    float amount; String accno;
    HDFC(){
        System.out.print("\nEnter Account Number : ");
        accno = Input.sc.next();
        System.out.print("Enter Amount : ");
        amount = Input.sc.nextFloat();
    }

    @Override
    public void deposit(){
        System.out.print("\nEnter Amount to be deposited : ");
        float a = Input.sc.nextFloat();
        System.out.println("Old amount : "+this.amount+"\nNew amount : "+(this.amount+a));
        this.amount += a;
    }
      
    @Override
    public void withdraw(){
        System.out.print("\nEnter Amount to be withdrawn : ");
        float a = Input.sc.nextFloat();
        System.out.println("Old amount : "+this.amount+"\nNew amount : "+(this.amount-a));
        this.amount -= a;
    }
      
    @Override
    public void details(){
        System.out.println("\nDetails : ");
        System.out.println("Account No. : "+this.accno);
        System.out.println("Amount : "+this.amount);
    }
}

public class Q1 {
    public static void main(String[] args) {
        Bank b1 = new SBI();
        b1.deposit();
        b1.withdraw();
        b1.details();
          
        b1 = new HDFC();
        b1.deposit();
        b1.withdraw();
        b1.details();
    }
}