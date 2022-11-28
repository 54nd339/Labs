import java.util.*;
class P3C{
    static Scanner sc=new Scanner(System.in);
    static P3C ob=new P3C();
    void p30(int n){
        for(int i=n,p=1;i>=1;i--,p++){
            for(int j=1;j<=p*2;j++)
            System.out.print(" ");
            for(int j=i;j>=1;j--)
            System.out.print(j+" ");
            System.out.println();
        }
        for(int i=n,p=2;i>=2;i--,p++){
            for(int j=3;j<=i*2;j++)
            System.out.print(" ");
            for(int j=p;j>=1;j--)
            System.out.print(j+" ");
            System.out.println();
        }
    }
    void p31(int n){
        for(int i=n,p=1;i>=1;i--,p++){
            for(int j=1;j<=p*2;j++)
            System.out.print(" ");
            for(int j=1;j<=i;j++)
            System.out.print(j+" ");
            System.out.println();
        }
        for(int i=n,p=2;i>=2;i--,p++){
            for(int j=3;j<=i*2;j++)
            System.out.print(" ");
            for(int j=1;j<=p;j++)
            System.out.print(j+" ");
            System.out.println();
        }
    }
    void p32(int n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=(n+1)-i;j++)
            System.out.print(j+" ");
            System.out.println();
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++)
            System.out.print(j+" ");
            System.out.println();
        }
    }
    void p33(int n){
        for(int i=n;i>=1;i--){
            for(int j=i;j>=1;j--)
            System.out.print(j+" ");
            System.out.println();
        }
        for(int i=2;i<=n;i++){
            for(int j=i;j>=1;j--)
            System.out.print(j+" ");
            System.out.println();
        }
    }
    public static void main(String args[]){
        System.out.print("Enter the no. 1-4, 0 to exit : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.p30(ch);
            else if(ch==2) ob.p31(ch);
            else if(ch==3) ob.p32(ch);
            else if(ch==4) ob.p33(ch);
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}