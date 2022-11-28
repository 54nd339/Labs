import java.util.*;
class Rot{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the dimension : ");
        int n=sc.nextInt();
        int ar[][]=new int[n][n];
        System.out.println("Enter the elements:");
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        ar[i][j]=sc.nextInt();

        System.out.println("Original Matrix:");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            System.out.print(ar[i][j]+" ");
            System.out.println();
        }

        System.out.println("New Matrix:");
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--)
            System.out.print(ar[j][i]+" ");
            System.out.println();
        }
        sc.close();
    }
}