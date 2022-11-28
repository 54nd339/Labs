import java.util.*;
class ISBN{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter The ISBN code : ");
        int n=sc.nextInt(),m=n,k=0,s=0;
        while(n!=0){
            k++;n/=10;
        }
        n=m;
        if(k==10){
            while(n!=0){
                int r=n%10;
                s+=r*k;
                k--;n/=10;
            }
            if(s%11==0)
            System.out.print("Legal ISBN.");
            else
            System.out.print("Illegal ISBN.");
        }else
        System.out.print("Illegal ISBN.");
        sc.close();
    }
}