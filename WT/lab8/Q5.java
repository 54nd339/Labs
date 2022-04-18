import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class TimeException extends Exception{
    TimeException(String s){
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
    void checkTime(int x, int y, int z)throws TimeException{
        if(x<0 || x>24)
            throw new TimeException("HrsException Handled");
        else
            System.out.println("Hours : "+x);
        if(y<0 || y>60)
            throw new TimeException("MinException Handled");
        else
            System.out.println("Minutes : "+y);
        if(z<0 || z>60)
            throw new TimeException("SecException Handled");
        else
            System.out.println("Seconds : "+z);
    }
}

public class Q5{
    public static void main(String args[]){
        Time ob = new Time();
        try{
            ob.checkTime(ob.h, ob.m, ob.s);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
        }
    }
}