import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class HrsException extends Exception{
    HrsException(String s){
        super(s);
    }
}
class MinException extends Exception{
    MinException(String s){
        super(s);
    }
}
class SecException extends Exception{
    SecException(String s){
        super(s);
    }
}
class Time{
    int h, m, s;
    Time(){
        System.out.print("Enter HH:MM:SS :");
        h = Input.sc.nextInt();
        m = Input.sc.nextInt();
        s = Input.sc.nextInt();
    }
    void checkHrs(int x)throws HrsException{
        if(x<0 || x>24)
            throw new HrsException("HrsException Handled");
        else
            System.out.println("Hours : "+x);
    }
    void checkMin(int x)throws MinException{
        if(x<0 || x>60)
            throw new MinException("MinException Handled");
        else
            System.out.println("Minutes : "+x);
    }
    void checkSec(int x)throws SecException{
        if(x<0 || x>60)
            throw new SecException("SecException Handled");
        else
            System.out.println("Seconds : "+x);
    }
}
public class Q5{
    public static void main(String args[]){
        Time ob = new Time();
        try{
            ob.checkHrs(ob.h);
            ob.checkMin(ob.m);
            ob.checkSec(ob.s);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
        }
    }
}