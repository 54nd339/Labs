import java.util.*;
class PT{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a no. : ");
        int n=sc.nextInt(),m=n,p1=0,p2=0,p3=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if((int)Math.pow(i,2)+(int)Math.pow(j,2)==(int)Math.pow(k,2)){
                        p1=i;p2=j;p3=k;
                        System.out.println(p1+", "+p2+", "+p3);
                    }
                }
            }
            if(i==m)
            n+=(m-p1);
        }
        System.out.println("The Pythagorean Triplet nearest to "+n+" is "+p1+", "+p2+", "+p3);
        sc.close();
    }
}