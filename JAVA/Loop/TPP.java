import java.util.*;
class TPP{
    static Scanner sc=new Scanner(System.in);
    static Prime ob=new Prime();
    static TPP ob1=new TPP();
    void twin(){
        System.out.print("Enter a no.:");
        int n=sc.nextInt(),m=n,p1=0,p2=0;
        for(int i=1;i<=n;i++){
            if(ob.isPrime(i) && ob.isPrime(i+2)){
                p1=i;p2=i+2;
                System.out.println("p1="+p1+" p2="+p2);
            }
            if(i==m)
            n+=(m-p1);
        }
        System.out.println("The Twin Prime nearest to "+n+" is "+p1+" and "+p2);
    }
    void triplet(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt(),m=n,p1=0,p2=0,p3=0;
        for(int i=1;i<=n;i++){
            if(ob.isPrime(i) && ob.isPrime(i+2) && ob.isPrime(i+6)){
                p1=i;p2=i+2;p3=i+6;
                System.out.println("p1="+p1+" p2="+p2+" p3="+p3);
            }
            if(ob.isPrime(i) && ob.isPrime(i+4) && ob.isPrime(i+6)){
                p1=i;p2=i+4;p3=i+6;
                System.out.println("p1="+p1+" p2="+p2+" p3="+p3);
            }
            if(i==m)
            n+=(m-p1);
        }
        System.out.println("The Prime Triplet nearest to "+n+" is "+p1+", "+p2+" and "+p3);
    }
    public static void main(String args[]){
        System.out.println("1. Print twin prime No.");
        System.out.println("2. Print triplet Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob1.twin();
            else if(ch==2) ob1.triplet();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}