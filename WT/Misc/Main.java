import java.util.*;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class NoMoneyException extends Exception{
    NoMoneyException(String s){
        super(s);
    }
}
class ATM{
    int rs2000, rs500, rs100;
    ATM(){
        System.out.print("Enter No. of 100s in the ATM : ");
        rs100 = Input.sc.nextInt();
        System.out.print("Enter No. of 500s in the ATM : ");
        rs500 = Input.sc.nextInt();
        System.out.print("Enter No. of 2000s in the ATM : ");
        rs2000 = Input.sc.nextInt();
    }
    void display(){
        System.out.println("No. of 100s in the ATM : "+rs100);
        System.out.println("No. of 500s in the ATM : "+rs500);
        System.out.println("No. of 2000s in the ATM : "+rs2000);
    }
    void withdraw(int x)throws NoMoneyException{
        if(x <= rs100*100 + rs500*500 + rs2000*2000 && x%100 == 0){
            int t2000 = 0, t500 = 0;
            if(x > 2000 && rs2000 > 0){
                if(x < rs2000*2000){
                    t2000 = x/2000;
                    rs2000 -= t2000;
                    x = x%(2000*t2000);
                }
                else{
                    rs2000 = 0;
                    x -= rs2000*2000;
                }
            }
            if(x > 500 && rs500 > 0){
                if(x < rs500*500){
                    t500 = x/500;
                    rs500 -= t500;
                    x = x%(500*t500);
                }
                else{
                    rs500 = 0;
                    x -= rs500*500;
                }
            }
            if(x > 100 && rs100 > 0){
                if(x < rs100*100){
                    rs100 -= x/100;
                }
                else{
                    rs2000 += t2000;
                    rs500 += t500;
                    throw new NoMoneyException("Itnaa pesaa nhi he bc..");
                }
            }
        }
        else
            throw new NoMoneyException("Itnaa pesaa nhi he bc..");
    }
}
public class Main {
    public static void main(String[] args) {
        ATM ob = new ATM();
        try{
            System.out.print("Enter Amount to be withdrawn : ");
            int amount = Input.sc.nextInt();
            ob.withdraw(amount);
            ob.display();
        }
        catch(Exception m){
            System.out.println(m.getMessage());
        }
    }
}