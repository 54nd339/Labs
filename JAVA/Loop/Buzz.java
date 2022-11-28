import java.util.*;
class Buzz{
    static Scanner sc=new Scanner(System.in);
    static Buzz ob=new Buzz();
    boolean isBuzz(int n){
        if(n%10==7 || n%7==0)
        return true;
        else
        return false;
    }
    void buzNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isBuzz(n))
        System.out.println(n+" is a Buzz no.");
        else
        System.out.println(n+" is Not a Buzz no.");
    }
    void buzSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isBuzz(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Buzz No.");
        System.out.println("2. Print Buzz Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.buzNo();
            else if(ch==2) ob.buzSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}   