import java.util.*;
class Perfect{
    static Scanner sc=new Scanner(System.in);
    static Perfect ob=new Perfect();
    boolean isPer(int n){
        int s=0;
        for(int i=1;i<n;i++){
            if(n%i==0)
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
        if(ob.isPer(n))
        System.out.println(n+" is a Perfect no.");
        else
        System.out.println(n+" is not a Perfect no.");
    }
    void perSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isPer(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Perfect No.");
        System.out.println("2. Print Perfect Series.");
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