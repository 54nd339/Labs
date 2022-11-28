import java.util.*;
class PP{
    static Scanner sc=new Scanner(System.in);
    static PP ob=new PP();
    boolean isPP(int n){
        int s=0;
        Prime ob=new Prime();
        for(int i=1;i<n;i++){
            if(n%i==0 && (i==1?true:ob.isPrime(i)))
            s+=i;
        }
        if(s==n)
        return true;
        else
        return false;
    }
    void perNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isPP(n))
        System.out.println(n+" is a Prime Perfect no.");
        else
        System.out.println(n+" is not a Prime Perfect no.");
    }
    void perSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
        if(ob.isPP(i))
        System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Prime Perfect No.");
        System.out.println("2. Print Prime Perfect Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.perNo();
            else if(ch==2) ob.perSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}