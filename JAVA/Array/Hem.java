import java.util.*;
class Hem{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the no. of binary digits : ");
        int n=sc.nextInt();
        int ar[]=new int[n];
        System.out.println("Enter the 1st binary & 1 digit per time : ");
        for(int i=0;i<n;i++)
            ar[i]=sc.nextInt();
        int ar1[]=new int[n];
        System.out.println("Enter the 2nd binary & 1 digit per time : ");
        for(int i=0;i<n;i++)
            ar1[i]=sc.nextInt();
        int k=0,d=0;
        for(int i=0;i<n;i++){
            if(ar[k]!=ar1[i])
            d++;k++;
        }
        System.out.println("Hemming Distance : "+d);
        sc.close();
    }
}