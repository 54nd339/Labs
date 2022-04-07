import java.util.Scanner;
class NegativeNumberException extends Exception{
    NegativeNumberException(String s){
        super(s);
    }
}
public class Q4{
    static void ProcessInput(int x)throws NegativeNumberException{
        if(x<0)
            throw new NegativeNumberException("NegativeNumberException Handled");
        else
            System.out.println("out : "+(x*2));
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a no. : ");
        int x = sc.nextInt();
        try{
            ProcessInput(x);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
        }
        sc.close();
    }
}