import java.util.*;
class Mobius{
    static Scanner sc=new Scanner(System.in);
    static Mobius ob=new Mobius();
    int mobVal(int n){
        int c=0;
        if(n==1)
        System.exit(1);
        for(int i=2;i<=n;i++){
            int c1=0;
            while(n%i==0){
                n/=i;
                c1++;
                if(c1==2){
                    c=0;
                    break;
                }
                c++;
            }
            if(c==-1){
                c=0;
                break;
            }
        }
        if(c==0)
        return (0);
        else
        return((int)Math.pow(-1,c));
    }
    void mobNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        System.out.print("Mobius Value of "+n+" is "+ob.mobVal(n));
    }
    void mobSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=2;i<=n;i++)
        System.out.println("Mobius Value of "+i+" is "+ob.mobVal(i));
    }
    public static void main(String args[]){
        System.out.println("1. Check Mobius No.");
        System.out.println("2. Print Mobius Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.mobNo();
            else if(ch==2) ob.mobSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}