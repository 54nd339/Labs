import java.util.*;
class P3B{
    static Scanner sc=new Scanner(System.in);
    static P3B ob=new P3B();
    void p30(int n){
        for(int i=1,m=n,d=1;i<=n;i++,m--,d+=2){
            for(int j=1;j<=m;j++)
            System.out.print((char)(j+64)+" ");
            for(int j=1;j<=d*2;j++)
            System.out.print(" ");
            for(int j=m;j>=1;j--)
            System.out.print((char)(j+64)+" ");
            System.out.println();
        }
    }
    void p31(int n){
        for(int i=1,m=n,d=1;i<=n;i++,m--,d+=2){
            for(int j=m;j>=1;j--)
            System.out.print((char)(j+64)+" ");
            for(int j=1;j<=d*2;j++)
            System.out.print(" ");
            for(int j=1;j<=m;j++)
            System.out.print((char)(j+64)+" ");
            System.out.println();
        }
    }
    void p32(int n){
        for(int i=n,m=1,d=n*2-1;i>=1;i--,m++,d-=2){
            for(int j=1;j<=m;j++)
            System.out.print((char)(j+64)+" ");
            for(int j=1;j<=d*2;j++)
            System.out.print(" ");
            for(int j=m;j>=1;j--)
            System.out.print((char)(j+64)+" ");
            System.out.println();
        }
    }
    void p33(int n){
        for(int i=n,m=1,d=n*2-1;i>=1;i--,m++,d-=2){
            for(int j=m;j>=1;j--)
            System.out.print((char)(j+64)+" ");
            for(int j=1;j<=d*2;j++)
            System.out.print(" ");
            for(int j=1;j<=m;j++)
            System.out.print((char)(j+64)+" ");
            System.out.println();
        }
    }
    void p34(int n){
        ob.p30(n);ob.p32(n);
    }
    void p35(int n){
        ob.p30(n);ob.p33(n);
    }
    void p36(int n){
        ob.p31(n);ob.p32(n);
    }
    void p37(int n){
        ob.p31(n);ob.p33(n);
    }
    public static void main(String args[]){
        System.out.print("Enter the no. 1-8, 0 to exit : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.p30(ch);
            else if(ch==2) ob.p31(ch);
            else if(ch==3) ob.p32(ch);
            else if(ch==4) ob.p33(ch);
            else if(ch==5) ob.p34(ch);
            else if(ch==6) ob.p35(ch);
            else if(ch==7) ob.p36(ch);
            else if(ch==8) ob.p37(ch);
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}