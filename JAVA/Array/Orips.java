import java.util.*;
class Orips{
    static Scanner sc=new Scanner(System.in);
    static Orips ob=new Orips();
    static int n,ar[][],k,c1,c2,r1,r2;
    void input(){
        System.out.print("Enter a no. : ");
        n=sc.nextInt();
        ar=new int[n][n];k=n*n;c1=0;c2=n-1;r1=0;r2=n-1;
    }
    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            System.out.print(ar[i][j]+"\t");
            System.out.println();
        }
    }
    void sp1(){
        ob.input();
        do{
            for(int i=c1;i<=c2;i++){
            ar[r1][i]=k;k--;}
            for(int i=r1+1;i<=r2;i++){
            ar[i][c2]=k;k--;}
            for(int i=c2-1;i>=c1;i--){
            ar[r2][i]=k;k--;}
            for(int i=r2-1;i>=r1+1;i--){
            ar[i][c1]=k;k--;}
            c1++;c2--;r1++;r2--;
        }while(k>=1);
        ob.print();
    }
    void sp2(){
        ob.input();
        do{
            for(int i=r1;i<=r2;i++){
            ar[i][c2]=k;k--;}
            for(int i=c2-1;i>=c1;i--){
            ar[r2][i]=k;k--;}
            for(int i=r2-1;i>=r1;i--){
            ar[i][c1]=k;k--;}
            for(int i=c1+1;i<=c2-1;i++){
            ar[r1][i]=k;k--;}
            c1++;c2--;r1++;r2--;
        }while(k>=1);
        ob.print();
    }
    void sp3(){
        ob.input();
        do{
            for(int i=c2;i>=c1;i--){
            ar[r2][i]=k;k--;}
            for(int i=r2-1;i>=r1;i--){
            ar[i][c1]=k;k--;}
            for(int i=c1+1;i<=c2;i++){
            ar[r1][i]=k;k--;}
            for(int i=r1+1;i<=r2-1;i++){
            ar[i][c2]=k;k--;}
            c1++;c2--;r1++;r2--;
        }while(k>=1);
        ob.print();
    }
    void sp4(){
        ob.input();
        do{
            for(int i=r2;i>=r1;i--){
            ar[i][c1]=k;k--;}
            for(int i=c1+1;i<=c2;i++){
            ar[r1][i]=k;k--;}
            for(int i=r1+1;i<=r2;i++){
            ar[i][c2]=k;k--;}
            for(int i=c2-1;i>=c1+1;i--){
            ar[r2][i]=k;k--;}
            c1++;c2--;r1++;r2--;
        }while(k>=1);
        ob.print();
    }
    void sp5(){
        ob.input();
        do{
            for(int i=c1;i<=c2;i++){
            ar[r2][i]=k;k--;}
            for(int i=r2-1;i>=r1;i--){
            ar[i][c2]=k;k--;}
            for(int i=c2-1;i>=c1;i--){
            ar[r1][i]=k;k--;}
            for(int i=r1+1;i<=r2-1;i++){
            ar[i][c1]=k;k--;}
            c1++;c2--;r1++;r2--;
        }while(k>=1);
        ob.print();
    }
    void sp6(){
        ob.input();
        do{
            for(int i=r1;i<=r2;i++){
            ar[i][c1]=k;k--;}
            for(int i=c1+1;i<=c2;i++){
            ar[r2][i]=k;k--;}
            for(int i=r2-1;i>=r1;i--){
            ar[i][c2]=k;k--;}
            for(int i=c2-1;i>=c1+1;i--){
            ar[r1][i]=k;k--;}
            c1++;c2--;r1++;r2--;
        }while(k>=1);
        ob.print();
    }
    void sp7(){
        ob.input();
        do{
            for(int i=c2;i>=c1;i--){
            ar[r1][i]=k;k--;}
            for(int i=r1+1;i<=r2;i++){
            ar[i][c1]=k;k--;}
            for(int i=c1+1;i<=c2;i++){
            ar[r2][i]=k;k--;}
            for(int i=r2-1;i>=r1+1;i--){
            ar[i][c2]=k;k--;}
            c1++;c2--;r1++;r2--;
        }while(k>=1);
        ob.print();
    }
    void sp8(){
        ob.input();
        do{
            for(int i=r2;i>=r1;i--){
            ar[i][c2]=k;k--;}
            for(int i=c2-1;i>=c1;i--){
            ar[r1][i]=k;k--;}
            for(int i=r1+1;i<=r2;i++){
            ar[i][c1]=k;k--;}
            for(int i=c1+1;i<=c2-1;i++){
            ar[r2][i]=k;k--;}
            c1++;c2--;r1++;r2--;
        }while(k>=1);
        ob.print();
    }
    public static void main(String args[]){
        System.out.print("Enter a no. between 1 to 8, O to exit : ");
        int num=sc.nextInt();
        while(num!=0){
            if(num==1) ob.sp1();
            else if(num==2) ob.sp2();
            else if(num==3) ob.sp3();
            else if(num==4) ob.sp4();
            else if(num==5) ob.sp5();
            else if(num==6) ob.sp6();
            else if(num==7) ob.sp7();
            else if(num==8) ob.sp8();
            else if(num==0) break;
            else{
                System.out.print("Wrong Input. Enter another choice : ");
                num=sc.nextInt();
            }
            System.out.println("\nEnter any choice to continue : ");
            num=sc.nextInt();
        }
        sc.close();
    }
}