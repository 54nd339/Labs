import java.util.*;
class Tri{
    static Scanner sc=new Scanner(System.in);
    static Tri ob=new Tri();
    boolean isTri(int n){
        int s=0;boolean b=false;
        for(int i=1;i<=n;i++){
            s+=i;
            if(s==n){
                b=true;
                break;}   
        }
        return b;
    }
    void triNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isTri(n))
        System.out.print(n+" is a Triangular no.");
        else
        System.out.print(n+" is not a Triangular no.");
    }
    void triSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isTri(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Triangle No.");
        System.out.println("2. Print Triangle Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.triNo();
            else if(ch==2) ob.triSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}