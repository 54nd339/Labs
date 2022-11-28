import java.util.*;
class DetCal{
    static DetCal ob=new DetCal();
    int[][] tra(int ar[][],int n){
        int tra[][]=new int[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                tra[j][i]=ar[i][j];
        return tra;
    }
    int[][] submat(int ar[][],int er,int ec,int n){
        int subma[][]=new int[n-1][n-1];
        int r=-1;
        for (int i=0;i<n;i++){
            if(i==er)
                continue;
            r++;int c=-1;
            for (int j=0;j<n;j++){
                if(j==ec)
                    continue;
                subma[r][++c]=ar[i][j];
            }
        }
        return subma;
    }
    int det(int ar[][]){
        int n=ar.length;
        int sum=0;
        if(n==1)
            sum=ar[0][0];
        if(n==2)
            sum=ar[0][0]*ar[1][1]-ar[0][1]*ar[1][0];
        for(int i=0;i<n;i++)
            sum+=ob.cs(i)*ar[0][i]*ob.det(ob.submat(ar,0,i,n));
        return sum;
    }
    int cs(int i) {
        if (i%2==0)
            return 1;
        return -1;
    }
    int[][] cof(int ar[][],int n){
        int cof[][]=new int[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                int min=ob.det(ob.submat(ar,i,j,n));
                System.out.println("Minor of "+ar[i][j]+" is : "+min/2);
                cof[i][j]=(ob.cs(i)*ob.cs(j)*min)/2;
            }
        System.out.println();
        return cof;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the dimension of the Matrix : ");
        int n=sc.nextInt();
        System.out.println("Enter a "+n+"X"+n+" Matrix");
        int ar[][]=new int[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ar[i][j]=sc.nextInt();
        
        System.out.println("Original Matrix :");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print(ar[i][j]+"\t");
            System.out.println();
        }
        System.out.println();
        
        int k=0,c=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                if(ar[i][j]!=ar[j][i])
                    k=1;
                if(i==j && ar[i][j]==0)
                    c++;
            }
        if(k==0)
            System.out.println("It is a Symmetric Matrix.");
        else
            System.out.println("It is Not a Symmetric Matrix.");
        if(k==0 && c==3)
            System.out.println("It is a Skew Symmetric Matrix.");
        else
            System.out.println("It is Not a Skew Symmetric Matrix.");
        System.out.println();

        System.out.println("det of the matrix is : "+ob.det(ar));
        System.out.println();

        System.out.println("Transpose of the matrix is :");
        int tra[][]=ob.tra(ar,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print(tra[i][j]+"\t");
            System.out.println();
        }
        System.out.println();

        int cof[][]=ob.cof(ar,n);
        System.out.println("Cofactor of the matrix is : ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print(cof[i][j]+"\t");
            System.out.println();
        }
        System.out.println();

        System.out.println("Adjoint of the matrix is : ");
        int adj[][]=ob.tra(cof,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print(adj[i][j]+"\t");
            System.out.println();
        }
        System.out.println();
        
        System.out.println("Inverse of the matrix is : ");
        if(ob.det(ar)!=0)
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print((adj[i][j]*((double)1/ob.det(ar)))+"\t");
            System.out.println();
        }
        else
        System.out.println("Not Possible.");
        System.out.println();
        sc.close();
    }
}