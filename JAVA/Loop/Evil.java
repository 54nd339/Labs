import java.util.*;
class Evil{
    static Scanner sc=new Scanner(System.in);
    static Evil ob=new Evil();
    boolean isEvil(int n){
        int c=0;
        while(n!=0){
            int r=n%2;
            if(r==1)
            c++;
            n/=2;
        }
        if(c%2==0)
        return true;
        else
        return false;
    }
    void eviNo(){
        System.out.print("Entere a no. : ");
        int n=sc.nextInt();
        if(ob.isEvil(n))
        System.out.println(n+" is an Evil No.");
        else
        System.out.println(n+" is not an Evil No.");
    }
    void eviSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++){
            if(ob.isEvil(i))
            System.out.println(i);
        }
    }
    public static void main(String args[]){
        System.out.println("1. Check Evil No.");
        System.out.println("2. Print Evil Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.eviNo();
            else if(ch==2) ob.eviSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}