import java.util.*;
class P4{
    static Scanner sc=new Scanner(System.in);
    static P4 ob=new P4();
    void p40(int n){
        int p=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++,p++)
            System.out.print(p+" ");
            System.out.println();
        }
        p-=n;
        for(int i=n-1;i>=1;i--){
            for(int j=1;j<=i;j++,p--)
            System.out.print(p+" ");
            System.out.println();
        }
    }
    void p41(int n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)
            System.out.print(j+" ");
            System.out.println();
        }
        for(int i=n-1;i>=1;i--){
            for(int j=1;j<=i;j++)
            System.out.print(j+" ");
            System.out.println();
        }
    }
    void p42(int n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)
            System.out.print(i+" ");
            System.out.println();
        }
        for(int i=n-1;i>=1;i--){
            for(int j=1;j<=i;j++)
            System.out.print(i+" ");
            System.out.println();
        }
    }
    void p43(int n){
        for(int i=1;i<=(n/2)+1;i++){
            for(int j=1;j<=i*2;j++)
            System.out.print(" ");
            for(int j=i;j<=(n+1)-i;j++)
            System.out.print(j+" ");
            System.out.println();
        }
        for(int i=n/2;i>=1;i--){
            for(int j=1;j<=i*2;j++)
            System.out.print(" ");
            for(int j=i;j<=(n+1)-i;j++)
            System.out.print(j+" ");
            System.out.println();
        }
    }
    public static void main(String args[]){
        System.out.print("Enter the no. 1-4, 0 to exit : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.p40(ch);
            else if(ch==2) ob.p41(ch);
            else if(ch==3) ob.p42(ch);
            else if(ch==4) ob.p43(ch);
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}