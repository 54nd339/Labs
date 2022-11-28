import java.util.*;
class Remove{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a no. : ");
        int n=sc.nextInt(),s=0,c=0;
        while(n!=0){
            int r=n%10;
            if(r!=0){
                s=r*(int)Math.pow(10,c)+s;
                c++;
            }
            n/=10;
        }
        System.out.println("After removing zero : "+s);
        sc.close();
    }
}