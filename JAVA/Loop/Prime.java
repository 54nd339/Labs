import java.util.*;
class Prime{
    static Scanner sc=new Scanner(System.in);
    static Prime ob=new Prime();
    boolean isPrime(int n){
        int c=0;
        for(int i=1;i<=n;i++){
            if(n%i==0)
            c++;
        }
        if(c==2)
        return true;
        else
        return false;
    }
    void priNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isPrime(n))
        System.out.println(n+" is a Prime no.");
        else
        System.out.println(n+" is a Composite no.");
    }
    void priSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt(),i;
        for(i=1;i<=n;i++){
            if(ob.isPrime(i))
            System.out.println(i);
        }
    }
    public static void main(String args[]){
        System.out.println("1. Check Kaprekar No.");
        System.out.println("2. Print Kaprekar Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.priNo();
            else if(ch==2) ob.priSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}   