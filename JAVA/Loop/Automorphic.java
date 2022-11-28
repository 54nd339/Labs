import java.util.*;
class Automorphic{
    static Scanner sc=new Scanner(System.in);
    static Automorphic ob=new Automorphic();
    boolean isAuto(int n){
        int m=n;
        int c=0;
        while(m!=0){
            m/=10;
            c++;
        }
        int p=n*n;
        int r=p%(int)Math.pow(10,c);
        if(n==r)
        return true;
        else
        return false;
    }
    void autNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isAuto(n))
        System.out.print(n+" is an Automorphic No.");
        else
        System.out.print(n+" is Not an Automorphic No.");
    }
    void autSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isAuto(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Automorphic No.");
        System.out.println("2. Print Automorphic Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.autNo();
            else if(ch==2) ob.autSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}