import java.util.*;
class Palindrome{
    static Scanner sc=new Scanner(System.in);
    static Palindrome ob=new Palindrome();
    boolean isPalin(int n){
        int m=n;
        int s=0;
        while(n!=0){
            int r=n%10;
            s=s*10+r;
            n/=10;
        }
        if(s==m)
        return true;
        else
        return false;
    }
    void palNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isPalin(n))
        System.out.print(n+" is a Palindrome");
        else
        System.out.print(n+" is Not a Palindrome");
    }
    void palSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isPalin(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Palindrome No.");
        System.out.println("2. Print Palindrome Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.palNo();
            else if(ch==2) ob.palSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}