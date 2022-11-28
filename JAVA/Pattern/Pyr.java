import java.util.*;
class Pyr{
    void print(int ar[][],int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<2*n-1;j++){
                if(ar[i][j]==0)
                System.out.print(" ");
                else
                System.out.print(ar[i][j]+" ");
            }System.out.println();
        }System.out.println();
    }
    void arr(int n){
        Pyr ob=new Pyr();
        int ar[][]=new int[n][2*n-1];
        ar[0][n-1]=1;
        ob.pyr2(n,ar);
        ob.pyr1(n,ar);
    }
    void pyr1(int n,int ar[][]){
        Pyr ob=new Pyr();
        for(int i=1;i<n;i++)
        for(int j=0;j<2*n-1;j++){
            int l=j-1,r=j+1;
            if(l<0) l=2*n-2;
            if(r>2*n-2) r=0;
            ar[i][j]=ar[i-1][l]+ar[i-1][r];
        }
        ob.print(ar,n);
    }
    void pyr2(int n,int ar[][]){
        Pyr ob=new Pyr();
        int m=1;
        for(int i=1;i<n;i++)
        for(int j=0;j<=(n-1)+i;j++){
            int ul=j-1,ur=j+1,l=j-2;
            if(ul<0) ul=2*n-2;
            if(l<0) l=(2*n-2)+(l+1);
            if(ur>2*n-2) ur=0;
            if(ar[i-1][ur]>0 && ar[i][l]+ar[i-1][ul]==0){
                ar[i][j]=m;continue;
            }
            ar[i][j]=ar[i][l]+ar[i-1][ul];
            if(ar[i][j]>0)
            m=ar[i][j];
        }
        ob.print(ar,n);
    }
    public static void main(String args[]){
        Pyr ob=new Pyr();
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter Row No. : ");
        int n=sc.nextInt();
        ob.arr(n);
        sc.close();
    }
}