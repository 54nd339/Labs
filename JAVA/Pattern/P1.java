import java.util.*;
class P1{
    static Scanner sc=new Scanner(System.in);
    static P1 ob =new P1();
    void p10(int n){
        for(int i=1,m=n;i<=n;i++,m--){
            for(int j=1;j<=m;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++)
            System.out.print((char)(i+64)+" ");
            System.out.println();
        }
        for(int i=(n-1),m=2;i>=1;i--,m++){
            for(int j=1;j<=m;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++)
            System.out.print((char)(i+64)+" ");
            System.out.println();
        }
    }
    void p11(int n){
        for(int i=1,m=n;i<=n;i++,m--){
            for(int j=1;j<=m;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++)
            System.out.print(i+" ");
            System.out.println();
        }
        for(int i=(n-1),m=2;i>=1;i--,m++){
            for(int j=1;j<=m;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++)
            System.out.print(i+" ");
            System.out.println();
        }
    }
    void p12(int n){
        for(int i=1,m=n;i<=n;i++,m--){
            for(int j=1;j<=m*2;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++)
            System.out.print(j+" ");
            for(int j=i-1;j>=1;j--)
            System.out.print(j+" ");
            System.out.println();
        }
        for(int i=(n-1),m=2;i>=1;i--,m++){
            for(int j=1;j<=m*2;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++)
            System.out.print(j+" ");
            for(int j=i-1;j>=1;j--)
            System.out.print(j+" ");
            System.out.println();
        }
    }
    void p13(int n){
        for(int i=1,m=n;i<=n;i++,m--){
            for(int j=1;j<=m*2;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++)
            System.out.print((char)(j+64)+" ");
            for(int j=i-1;j>=1;j--)
            System.out.print((char)(j+64)+" ");
            System.out.println();
        }
        for(int i=(n-1),m=2;i>=1;i--,m++){
            for(int j=1;j<=m*2;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++)
            System.out.print((char)(j+64)+" ");
            for(int j=i-1;j>=1;j--)
            System.out.print((char)(j+64)+" ");
            System.out.println();
        }
    }
    void p14(int n){
        int k=1;
        for(int i=1,m=n;i<=n;i++,m--){
            for(int j=1;j<=m;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++,k++)
            System.out.print((char)(k+64)+" ");
            System.out.println();
        }
        for(int i=(n-1),l=9,m=2;i>=1;i--,m++,l-=2){
            k-=l;
            for(int j=1;j<=m;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++,k++)
            System.out.print((char)(k+64)+" ");
            System.out.println();
        }
    }
    void p15(int n){
        for(int i=n;i>=1;i--){
            for(int j=1;j<=i;j++)
            System.out.print("  ");
            for(int j=1;j<=(n-i)+1;j++)
            System.out.print("* ");
            System.out.println();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i+1;j++)
            System.out.print("  ");
            for(int j=2;j<=(n-i)+1;j++)
            System.out.print("* ");
            System.out.println();
        }
    }
    public static void main(String args[]){
        System.out.print("Enter the no. 1-6, 0 to exit : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.p10(ch);
            else if(ch==2) ob.p11(ch);
            else if(ch==3) ob.p12(ch);
            else if(ch==4) ob.p13(ch);
            else if(ch==5) ob.p14(ch);
            else if(ch==6) ob.p15(ch);
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}