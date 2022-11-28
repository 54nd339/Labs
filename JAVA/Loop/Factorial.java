import java.util.*;
class Factorial{
    static Scanner sc=new Scanner(System.in);
    static Factorial ob=new Factorial();
    int fact(int n){
        if(n==0)
        return (1);
        else
        return(n*fact(n-1));
    }
    void fact(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        System.out.print("Factorial = "+ob.fact(n));
    }
    void facs(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
        System.out.println(i+"!="+ob.fact(i));
    }
    public static void main(String args[]){
        System.out.println("1. Print Facorial of a No.");
        System.out.println("2. Print Factorial of a Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.fact();
            else if(ch==2) ob.fact();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}