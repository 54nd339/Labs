import java.util.*;
class Goldbach{
    void gold(int n){
        Prime ob=new Prime();
        System.out.println("Prime Pairs are:");
        if(n>4 && n%2==0){
            for(int i=3;i<=n;i++)
            for(int j=i;j<=n;j++)
            if(ob.isPrime(i) && ob.isPrime(j) && i+j==n)
            System.out.println(i+"\t"+j);
        }
        else
        System.out.println("Wrong Input");
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter an Even no. more than 4 : ");
        int n=sc.nextInt();
        Goldbach ob=new Goldbach();
        ob.gold(n);
        sc.close();
    }
}