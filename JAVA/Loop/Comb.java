import java.util.*;
class Comb{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a no. b/w 1 to 9 : ");
        int n=sc.nextInt(),c2=0;
        for(int i=(int)Math.pow(10,n-1);i<(int)Math.pow(10,n);i++){
            int c=0;
            for(int j=1;j<=n;j++){
                int c1=0,m=i;
                while(m!=0){
                    int num=m%10;
                    if(num==j)
                    c1++;
                    m/=10;
                }
                if(c1==1)
                c++;
            }
            if(c==n){
            System.out.println(i);c2++;}
        }
        System.out.println("Total no. of Combinations ="+c2);
        sc.close();
    }
}