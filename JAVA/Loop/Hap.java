import java.util.*;
class Hap{
    static Scanner sc=new Scanner(System.in);
    static Hap ob=new Hap();
    boolean isHap(int n){
        int s=n;
        while(s>9){
            n=s;s=0;
            while(n!=0){
                int r=n%10;
                s=s+r*r;n/=10;
            }
        }
        if(s==1)
        return true;
        else
        return false;
    }
    void hapNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isHap(n))
        System.out.println(n+" is a Happy no.");
        else
        System.out.println(n+" is not a Happy no.");
    }
    void hapSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isHap(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Happy No.");
        System.out.println("2. Print Happy Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.hapNo();
            else if(ch==2) ob.hapSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}