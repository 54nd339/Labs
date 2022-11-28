import java.util.*;
class CP{
    static Scanner sc=new Scanner(System.in);
    static CP ob=new CP();
    boolean isCP(int n){
        int m=n,c=0;
        Prime ob=new Prime();boolean b=true;
        while(m!=0){
            c++;m/=10;
        }
        m=n;
        for(int c1=0;c1<c;c1++){
            b=true;
            if(ob.isPrime(m)==false){
                b=false;break;
            }
            //System.out.println(m);
            int q=(int)(m/Math.pow(10,c-1));
            int r=(int)(m%Math.pow(10,c-1));
            m=r*10+q;
        }
        if(b)
        return true;
        else
        return false;
    }
    void cp(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isCP(n))
        System.out.println(n+" is a Circular Prime");
        else{
        //System.out.println(m);
        System.out.println(n+" is not a Circular Prime");}
    }
    void cs(){
        System.out.print("enter the last no. : ");
        int n=sc.nextInt();
        for (int i=2;i<=n;i++)
            if(ob.isCP(i))
                System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Circular Prime No.");
        System.out.println("2. Print Circular Prime Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.cp();
            else if(ch==2) ob.cs();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}