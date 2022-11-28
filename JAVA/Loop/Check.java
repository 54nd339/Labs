import java.util.*;
class Check{
    static Scanner sc=new Scanner(System.in);
    void checkF(int n){
        int a=0,b=1,c,flag=0;
        do{
            if(n==a){
                flag=1;
                break;
            }
            c=b;b+=a;a=c;
        }while(a<=n);
        if(flag==1)
        System.out.println("Present in Fibonacci Series");
        else
        System.out.println("Absent in Fibonacci Series");
    }
    void checkT(int n){
        int a=0,b=1,c=1,d,flag=0;
        do{
            if(n==a){
                flag=1;
                break;
            }
            d=c;c+=a+b;a=b;b=d;
        }while(a<=n);
        if(flag==1)
        System.out.println("Present in Tribonacci Series");
        else
        System.out.println("Absent in Tribonacci Series");
    }
    public static void main(String args[]){
        Check ob=new Check();
        System.out.print("Enter the no. : ");
        int n=sc.nextInt();
        ob.checkF(n);
        ob.checkT(n);
    }
}