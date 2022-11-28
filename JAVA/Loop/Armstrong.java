import java.util.*;
class Armstrong{
    static Scanner sc=new Scanner(System.in);
    static Armstrong ob=new Armstrong();
    boolean isArm(int n){
        int m=n,s=0;
        while(n>0){
            int r=n%10;
            s+=(r*r*r);
            n/=10;
        }
        if(m==s)
        return true;
        else
        return false;
    }
    void armNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isArm(n))
        System.out.print(n+" is an Armstrong no.");
        else
        System.out.print(n+" is Not an Armstrong No.");
    }
    void armSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isArm(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Armstrong No.");
        System.out.println("2. Print Armstrong Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.armNo();
            else if(ch==2) ob.armSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}