import java.util.*;
class MatCal{
    static int m=0,n=0,p=0,q=0;
    void sum(int fir[][],int sec[][]){
        int sum[][]=new int[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                sum[i][j]=fir[i][j]+sec[i][j];
        System.out.println("sum:");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                System.out.print(sum[i][j]+"\t");
            System.out.println();}
    }
    void dif(int fir[][],int sec[][]){
        int dif[][]=new int[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dif[i][j]=fir[i][j]-sec[i][j];
        System.out.println("difference:");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                System.out.print(dif[i][j]+"\t");
            System.out.println();}
    }
    void pro(int fir[][],int sec[][]){
        int pro[][]=new int[m][n],sum=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<q;j++){
                for(int k=0;k<p;k++)
                    sum+=fir[i][k]*sec[k][j];
                pro[i][j]=sum;
                sum=0;
            }
        System.out.println("product:");
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++)
                System.out.print(pro[i][j]+"\t");
            System.out.println();}
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        MatCal ob=new MatCal();
        System.out.print("Enter the no. of rows of 1st matrix : ");
        m=sc.nextInt();
        System.out.print("Enter the no. of columns of 1st matrix : ");
        n=sc.nextInt();
        int fir[][]=new int[m][n];
        System.out.println("Enter the Elements of the matrix :");
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                fir[i][j]=sc.nextInt();
        System.out. println();
        
        System.out.print("Enter the no. of rows of 2nd matrix : ");
        p=sc.nextInt();
        System.out.print("Enter the no. of columns of 2nd matrix : ");
        q=sc.nextInt();
        int sec[][]=new int[p][q];
        System.out.println("Enter the Elements of the matrix :");
        for(int i=0;i<p;i++)
            for(int j=0;j<q;j++)
                sec[i][j]=sc.nextInt();
        System.out. println();

        if(m==p && n==q){
            ob.sum(fir,sec);
            System.out. println();
            ob.dif(fir,sec);
            System.out. println();
        }
        else{
            System.out.println("Sum and difference not possible.");
            System.out. println();
        }

        if(n!=p)
        System.out.println("Product not possible.");
        else
        ob.pro(fir,sec);
        sc.close();
    }
}