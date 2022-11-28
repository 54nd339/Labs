import java.util.*;
class Spec2{
    static Scanner sc=new Scanner(System.in);
    static Spec2 ob=new Spec2();
    boolean isSp2(int n){
        int s=0,p=1;
        while(n!=0){
            int r=n%10;
            s+=r;p*=r;
            n/=10;
        }
        if(s+p==n)
        return true;
        else
        return false;
    }
    void sp2(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isSp2(n))
        System.out.println(n+" is a Sum Product digit no.");
        else
        System.out.println(n+" is not a Sum Product digit no.");
    }
    void perSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
        if(ob.isSp2(i))
        System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Sum Product No.");
        System.out.println("2. Print Sum Product Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.sp2();
            else if(ch==2) ob.perSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}