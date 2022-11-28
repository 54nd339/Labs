import java.util.*;
class Pronic{
    static Scanner sc=new Scanner(System.in);
    static Pronic ob=new Pronic();
    boolean isPron(int n){
        boolean b=false;
        for(int i=0;i<=n;i++)
        if(i*(i+1)==n){
        b=true;break;}
        return b;
    }
    void proNo(){
        System.out.print("Entere a no. : ");
        int n=sc.nextInt();
        if(ob.isPron(n))
        System.out.println(n+" is an Pronic No.");
        else
        System.out.println(n+" is not an Pronic No.");
    }
    void proSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isPron(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Pronic No.");
        System.out.println("2. Print Pronic Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.proNo();
            else if(ch==2) ob.proSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}