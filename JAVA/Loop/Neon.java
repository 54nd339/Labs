import java.util.*;
class Neon{
    static Scanner sc=new Scanner(System.in);
    static Neon ob=new Neon();
    boolean isNeo(int n){
        int m=n*n;
        int s=0;
        while(m!=0){
            int r=m%10;
            s+=r;
            m/=10;
        }
        if(s==n)
        return true;
        else
        return false;
    }
    void neNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isNeo(n))
        System.out.print(n+" is a Neon no.");
        else
        System.out.print(n+" is Not a Neon No.");
    }
    void neSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isNeo(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Neon No.");
        System.out.println("2. Print Neon Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.neNo();
            else if(ch==2) ob.neSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}