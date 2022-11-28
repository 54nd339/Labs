import java.util.*;
class Duck{
    static Scanner sc=new Scanner(System.in);
    static Duck ob=new Duck();
    boolean isDuc(int n){
        int r=0,c=0;
        for(int i=n;i!=0;i/=10){
            r=i%10;
            if (r==0){
                c=1;break;
            }
        }
        if(c==1)
            return true;
        else
            return false;
    }
    void ducNo(){
        System.out.print("enter a no. : ");
        int n=sc.nextInt();
        if (ob.isDuc(n))
            System.out.print(n+" is a duck no.");
        else
            System.out.print(n+" is not a duck no.");
    }
    void ducSer(){
        System.out.print("enter the last Integer : ");
        int n=sc.nextInt();
        for (int i=1;i<=n;i++)
            if(ob.isDuc(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Duck No.");
        System.out.println("2. Print Duck Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.ducNo();
            else if(ch==2) ob.ducSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}