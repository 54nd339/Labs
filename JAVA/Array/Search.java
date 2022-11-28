import java.util.*;
class Search{
    static Scanner sc=new Scanner(System.in);
    static Search ob=new Search();
    int[] accept(){
        System.out.print("Enter the no. of elements : ");
        int n1=sc.nextInt();
        int ar[]=new int[n1];
        System.out.println("Enter "+n1+" nos. : ");
        for(int i=0;i<ar.length;i++)
        ar[i]=sc.nextInt();
        return ar;
    }
    int search(){
        System.out.print("Enter the no. to be searched : ");
        int n=sc.nextInt();
        return n;
    }
    void print(boolean b){
        if(b)
        System.out.print("Found");
        else
        System.out.print("Not Found");
    }
    void ls(){
        int ar[]=ob.accept();
        int n=ob.search(),k=0,i=0;
        for(i=0;i<ar.length;i++)
        if(ar[i]==n){
            k=1;
            break;
        }
        if(k==1) ob.print(true);
        else ob.print(false);
    }
    void bs(){
        int ar[]=ob.accept();
        int n=ob.search();
        for(int i=0;i<ar.length-1;i++)
            for(int j=0;j<ar.length-(i+1);j++)
                if(ar[j]>ar[j+1]){
                    int t=ar[j];
                    ar[j]=ar[j+1];
                    ar[j+1]=t;
                }
        int lb=0,ub=ar.length-1,k=0,p=0;
        while(lb<=ub){
            p=(lb+ub)/2;
            if(ar[p]<n)
            lb=p+1;
            if(ar[p]>n)
            ub=p-1;
            if(ar[p]==n){
                k=1;
                break;
            }
        }
        if(k==1) ob.print(true);
        else ob.print(false);
    }
    public static void main(String args[]){
        System.out.println("1. Linear Search");
        System.out.println("2. Binary Search");
        System.out.println("Enter your choice : ");
        int n=sc.nextInt();
        while(n!=0){
            if(n==1) {ob.ls();n=0;}
            else if(n==2) {ob.bs();n=0;}
            else{
                System.out.println("Wrong Choice. Enter again : ");
                n=sc.nextInt();
            }
        }
    }
}