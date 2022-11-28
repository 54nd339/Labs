import java.util.*;
class Series{
    static Scanner sc=new Scanner(System.in);
    static Series ob=new Series();
    void fib(){
        System.out.print("Enter the no. of terms : ");
        int n=sc.nextInt(),a=0,b=1,c;
        System.out.println("Fibonacci Series :");
        for(int i=1;i<=n;i++){
            System.out.println(a);
            c=b;b+=a;a=c;
        }
    }
    void trib(){
        System.out.print("Enter the nos. of terms : ");
        int n=sc.nextInt(),a=0,b=1,c=1,d;
        System.out.println("Tribbonacci Series :");
        for(int i=1;i<=n;i++){
            System.out.println(a);
            d=c;c+=a+b;a=b;b=d;
        }
    }
    public static void main(String args[]){
        System.out.println("1. Print Fibonacci Series.");
        System.out.println("2. Print Tribonacci Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.fib();
            else if(ch==2) ob.trib();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}       