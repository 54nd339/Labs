import java.util.*;
class MS{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter no. of rows : ");
        int n=sc.nextInt();
        int a[][]=new int[n][n];
        if(n%2!=0){
            int i=0,j=n/2,k=1;
            while(k<=n*n){
                a[i][j]=k++;
                i--;j++;
                if(i<0 && j>n-1){
                    i+=2;
                    j--;
                }
                if(i<0)
                    i=n-1;
                if(j>n-1)
                    j=0;
                if(a[i][j]>0){
                    i+=2;
                    j--;
                }
            }
        }
        else{
            int k=0;
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    a[i][j]=++k;
            int j=n-1;
            for(int i=0;i<n/2;i++){
                int t=a[i][i];
                a[i][i]=a[j][j];
                a[j][j]=t;
                t=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=t;
                j--;
            }
        }
        System.out.println("Magic Square of size "+n+"x"+n+" is : ");
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        System.out.print(a[i][j]+"\t");
        System.out.println();
        sc.close();
        }
    }
}