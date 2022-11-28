import java.util.*;
class Spec{
    static Scanner sc=new Scanner(System.in);
    static Spec ob=new Spec();
    boolean isSpec(int n){
        int s=0,p=1,m=n;
        while(m!=0){
            int r=m%10;
            for(int j=1;j<=r;j++)
            p*=j;
            s+=p;
            p=1;m/=10;
        }
        if(s==n)
        return true;
        else
        return false;
    }
    void speNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isSpec(n))
        System.out.println(n+" is a Special no.");
        else
        System.out.println(n+" is not a Special no.");
    }
    void speSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isSpec(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Special No.");
        System.out.println("2. Print Special Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.speNo();
            else if(ch==2) ob.speSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}