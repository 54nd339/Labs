import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class LessBalanceException extends Exception{
    LessBalanceException(String s){
        super(s);
    }
}
class Account{
    float amount;
    Account(){
        System.out.print("Enter minimum amount : ");
        amount = Input.sc.nextFloat();
    }
    void Deposit(){
        System.out.print("Enter amount to be deposited : ");
        float x = Input.sc.nextFloat();
        amount += x;
    }
    void Withdraw() throws LessBalanceException{
        System.out.print("Enter amount to be withdrawn (Min:500) : ");
        float x = Input.sc.nextFloat();
        if(x < 500 || x > amount)
            throw new LessBalanceException("Withdraw Amount Not valid");
        else
            amount -= x;
    }
}
public class Q7 {
    public static void main(String[] args){
        Account ob = new Account();
        System.out.println("1. Deposit\n2. Withdraw\n0. Exit");
        while(true){
            System.out.print("\nEnter your choice : ");
            int ch = Input.sc.nextInt();
            if(ch == 1) ob.Deposit();
            else if(ch == 2){
                try{
                    ob.Withdraw();
                }
                catch(Exception e){
                    System.out.println(e.getMessage());
                }
            }
            else if(ch == 0) break;
            else System.out.println("Wrong choice.");
            System.out.println("Current Balance : "+ob.amount);
        }
    }
}