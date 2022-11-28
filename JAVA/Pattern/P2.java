import java.util.*;
class P2{
    static Scanner sc=new Scanner(System.in);
    static P2 ob=new P2();
    void p20(int n){
        for(int i=1,k=n,p=65;i<=n;i++,k--,p++){
            for(int j=1;j<=i;j++)
            System.out.print(i+" ");
            for(int j=k;j>=1;j--)
            System.out.print((char)p+" ");
            System.out.println();
        }
    }
    void p21(int n){
        for(int i=1,k=n,p=65;i<=n;i++,k--,p++){
            for(int j=1;j<=i;j++)
            System.out.print((char)p+" ");
            for(int j=k;j>=1;j--)
            System.out.print(i+" ");
            System.out.println();
        }
    }
    void p22(int n){
        for(int i=1,k=n,p=65;i<=n;i++,k--,p++){
            for(int j=1;j<=i;j++)
            System.out.print(k+" ");
            for(int j=k;j>=1;j--)
            System.out.print((char)p+" ");
            System.out.println();
        }
    }
    void p23(int n){
        for(int i=1,k=n,p=65;i<=n;i++,k--,p++){
            for(int j=1;j<=i;j++)
            System.out.print((char)p+" ");
            for(int j=k;j>=1;j--)
            System.out.print(k+" ");
            System.out.println();
        }
    }
    void p24(int n){
        for(int i=n,k=1,p=65;i>=1;i--,k++,p++){
            for(int j=1;j<=i;j++)
            System.out.print((char)p+" ");
            for(int j=k;j>=1;j--)
            System.out.print(i+" ");
            System.out.println();
        }
    }
    void p25(int n){
        for(int i=n,k=1,p=65;i>=1;i--,k++,p++){
            for(int j=1;j<=i;j++)
            System.out.print(i+" ");
            for(int j=k;j>=1;j--)
            System.out.print((char)p+" ");
            System.out.println();
        }
    }
    void p26(int n){
        for(int i=n,k=1,p=65;i>=1;i--,k++,p++){
            for(int j=1;j<=i;j++)
            System.out.print((char)p+" ");
            for(int j=k;j>=1;j--)
            System.out.print(k+" ");
            System.out.println();
        }
    }
    void p27(int n){
        for(int i=n,k=1,p=65;i>=1;i--,k++,p++){
            for(int j=1;j<=i;j++)
            System.out.print(k+" ");
            for(int j=k;j>=1;j--)
            System.out.print((char)p+" ");
            System.out.println();
        }
    }
    void p28(int n){
        for(int i=1,p=2;i<=n;i++,p++){
            for(int j=1;j<=i;j++)
            System.out.print(i+" ");
            for(int j=p;j<=n;j++)
            System.out.print(j+" ");
            System.out.println();
        }
    }
    void p29(int n){
        for(int i=1,p=2;i<=n;i++,p++){
            for(int j=1;j<=i;j++)
            System.out.print((char)(64+i)+" ");
            for(int j=p;j<=n;j++)
            System.out.print((char)(64+j)+" ");
            System.out.println();
        }
    }
    public static void main(String args[]){
        System.out.print("Enter the no. 1-10, 0 to exit : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.p20(ch);
            else if(ch==2) ob.p21(ch);
            else if(ch==3) ob.p22(ch);
            else if(ch==4) ob.p23(ch);
            else if(ch==5) ob.p24(ch);
            else if(ch==6) ob.p25(ch);
            else if(ch==7) ob.p26(ch);
            else if(ch==8) ob.p27(ch);
            else if(ch==9) ob.p28(ch);
            else if(ch==10) ob.p29(ch);
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}