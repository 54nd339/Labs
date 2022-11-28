import java.util.*;
class DIM{
    static Scanner sc=new Scanner(System.in);
    static DIM ob=new DIM();
    void del(){
        System.out.print("Enter the no. of elements:");
        int n=sc.nextInt();
        int ar[]=new int[n+2];
        System.out.println("Enter "+n+" nos.:");
        for(int i=0;i<n;i++)
        ar[i]=sc.nextInt();
        System.out.print("Enter position of the element to be deleted:");
        int m=sc.nextInt();
        for(int i=m+1;i<n;i++)
        ar[i-1]=ar[i];
        n--;
        for(int i=0;i<n;i++)
        System.out.print(ar[i]+" ");
    }
    void uniq(){
        System.out.print("Enter the no. of elements:");
        int n=sc.nextInt();
        int ar[]=new int[n];
        int ar1[]=new int[n];
        System.out.println("Enter "+n+" nos.:");
        for(int i=0;i<n;i++)
        ar[i]=sc.nextInt();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            if(ar[i]==ar[j])
            ar[j]=0;
        }
        for(int j=0,i=0;j<n;j++)
            if(ar[j]!=0){
            ar1[i]=ar[j];i++;
        }
        System.out.print("Unique Array:");
        for(int i=0;i<n;i++)
        System.out.print(ar[i]+" ");
    }
    void ins(){
        System.out.print("Enter the no. of elements:");
        int n=sc.nextInt();
        int ar[]=new int[n+2];
        System.out.println("Enter "+n+" nos.:");
        for(int i=0;i<n;i++)
        ar[i]=sc.nextInt();
        System.out.print("Enter the element to be inserted:");
        int n1=sc.nextInt();
        System.out.print("Enter position of the element to be inserted:");
        int m=sc.nextInt();int i=0;
        for(i=n-1;i>=m;i--)
        ar[i+1]=ar[i];
        ar[m]=n1;
        n++;
        for(i=0;i<n;i++)
        System.out.print(ar[i]+" ");
    }
    void mer(){
        System.out.print("Enter the no. of elements in 1st Array:");
        int n=sc.nextInt();
        int ar[]=new int[n];
        System.out.println("Enter "+n+" nos.");
        for(int i=0;i<n;i++)
        ar[i]=sc.nextInt();
        System.out.print("Enter the no. of elements in 2nd Array:");
        int n1=sc.nextInt();
        int ar1[]=new int[n1];
        System.out.println("Enter "+n+" nos.");
        for(int i=0;i<n1;i++)
        ar1[i]=sc.nextInt();
        int ar2[]=new int[n+n1];
        for(int i=0;i<n;i++)
        ar2[i]=ar[i];
        for(int i=0;i<n1;i++)
        ar2[i+n]=ar1[i];
        for(int i=0;i<n+n1;i++)
        System.out.print(ar2[i]+" ");
    }
    public static void main(String args[]){
        System.out.println("1. delete an element from an array.");
        System.out.println("2. insert an element from an array.");
        System.out.println("3. merge 2 arrays.");
        System.out.println("4. check an array is unique.");
        System.out.println("0. exit");
        System.out.print("Enter your Choice : ");
        int n=sc.nextInt();
        while(n!=0){
            if(n==1) ob.del();
            else if(n==2) ob.ins();
            else if(n==3) ob.mer();
            else if(n==4) ob.uniq();
            else if(n==0) break;
            else{
                System.out.print("Wrong Input. Enter another choice : ");
                n=sc.nextInt();
            }
            System.out.print("\nEnter any choice to continue : ");
            n=sc.nextInt();
        }
    }
}