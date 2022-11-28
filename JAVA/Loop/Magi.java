import java.util.*;
class Magi{
    static Scanner sc=new Scanner(System.in);
    static Magi ob=new Magi();
    boolean isMagi(int n){
        int s=n;
        while(s>9){
            n=s;s=0;
            while(n!=0){
                int r=n%10;
                s+=r;n/=10;
            }
        }
        if(s==1)
        return true;
        else
        return false;
    }
    void magNo(){
        System.out.print("Enter a No. : ");
        int n=sc.nextInt();
        if(ob.isMagi(n))
        System.out.println(n+" is a Magic No.");
        else
        System.out.println(n+" is Not a Magic No.");
    }
    void magSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isMagi(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Magic No.");
        System.out.println("2. Print Magic Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.magNo();
            else if(ch==2) ob.magSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}