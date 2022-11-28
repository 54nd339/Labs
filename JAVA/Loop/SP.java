import java.util.*;
class SP{
    static Scanner sc=new Scanner(System.in);
    static SP ob=new SP();
    boolean isSP(int n){
        int s=0,p=1;
        while(n!=0){
            int r=n%10;
            s+=r;p*=r;
            n/=10;
        }
        if(s==p)
        return true;
        else
        return false;
    }
    void spNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isSP(n))
        System.out.println(n+" is a Sum Product digit no.");
        else
        System.out.println(n+" is not a Sum Product digit no.");
    }
    void spSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isSP(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Sum Product No.");
        System.out.println("2. Print Sum Product Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.spNo();
            else if(ch==2) ob.spSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}