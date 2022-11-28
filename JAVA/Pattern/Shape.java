class Shape{
    static Shape ob=new Shape();
    void print(char ar[][],int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            if(ar[i][j]==' ')
            System.out.print("  ");
            else
            System.out.print(ar[i][j]+" ");
            System.out.println();
        }
    }
    public static void squar(int n){
        char ar[][]=new char[n][n];
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(i==0||j==0||i==n-1||j==n-1)
        ar[i][j]='*';
        else
        ar[i][j]=' ';
        ob.print(ar,n);
    }
    public static void cross(int n){
        char ar[][]=new char[n][n];
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(i==j||i+j==n-1)
        ar[i][j]='*';
        else
        ar[i][j]=' ';
        ob.print(ar,n);
    }
    public static void rhom(int n){
        char ar[][]=new char[n][n];
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(j==(n/2)-i||j==(n/2)+i)
            ar[i][j]='*';
        else
            ar[i][j]=' ';
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++)
            if(ar[i][j]==' ')
            System.out.print("  ");
            else
            System.out.print(ar[i][j]+" ");
            System.out.println();
        }
        for(int i=(n-1)/2;i>=0;i--){
            for(int j=n-1;j>=0;j--)
            if(ar[i][j]==' ')
            System.out.print("  ");
            else
            System.out.print(ar[i][j]+" ");
            System.out.println();
        }
    }
}