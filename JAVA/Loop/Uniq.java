import java.util.*;
class Uniq{
    static Scanner sc=new Scanner(System.in);
    static Uniq ob=new Uniq();
    boolean isUniq(int n){
        int m=n,c=0;
        for(int i=0;i<10;i++){
            c=0;
            while(n!=0){
                int r=n%10;
                if(r==i)
                    c++;
                n=n/10;
            }
            if(c>1)
            break;
            n=m;
        }
        if(c==0||c==1)
        return true;
        else
        return false;
    }
    void uniNo(){
        System.out.print("Enter a No. : ");
        int n=sc.nextInt();
        if(ob.isUniq(n))
        System.out.println(n+" is an Unique no.");
        else
        System.out.println(n+" is not an Unique no.");
    }
    void uniSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int j=1;j<=n;j++)
            if(ob.isUniq(j))
            System.out.println(j);
    }
    public static void main(String args[]){
        System.out.println("1. Check Unique No.");
        System.out.println("2. Print Unique Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.uniNo();
            else if(ch==2) ob.uniSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}