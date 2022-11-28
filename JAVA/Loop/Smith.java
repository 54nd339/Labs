import java.util.*;
class Smith{
    static Scanner sc=new Scanner(System.in);
    static Smith ob=new Smith();
    boolean isSmit(int n){
        Prime obPr=new Prime();
        int s1=ob.digit(n);
        int k=n,s=0;
        if(obPr.isPrime(n))
            return false;
        else{
            for(int i=2;i<=k;i++){
                while(k%i==0){
                    k/=i;
                    s+=ob.digit(i);
                }
            }}
        if(s==s1)
            return true;
        else
            return false;
    }
    int digit(int k){
        int s1=0;
        while(k!=0){
            int r=k%10;
            s1+=r;
            k/=10;
        }
        return s1;
    }
    void smiNo(){
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        if(ob.isSmit(n))
            System.out.println(n+" is a Smith No.");
        else
            System.out.println(n+" is not a Smith No.");
    }
    void smiSer(){
        System.out.print("Enter the last no. : ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
            if(ob.isSmit(i))
            System.out.println(i);
    }
    public static void main(String args[]){
        System.out.println("1. Check Smith No.");
        System.out.println("2. Print Smith Series.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.smiNo();
            else if(ch==2) ob.smiSer();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}