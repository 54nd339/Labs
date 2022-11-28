import java.util.*;
class Niven{
    static Scanner sc=new Scanner(System.in);
    static Niven ob=new Niven();
    boolean isNiv(int n){
        int s=0,m=n;
        while(n!=0){
            s+=n%10;
            n/=10;
        }
        if(m%s==0)
            return true;
        else
        return false;
    }
    void nivNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isNiv(n))
            System.out.print(n+" is a Harshad Number");
        else
            System.out.print(n+" is not a Harshad Number");
    }
    void harSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isNiv(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Niven No.");
        System.out.println("2. Print Niven Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.nivNo();
            else if(ch==2) ob.harSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}