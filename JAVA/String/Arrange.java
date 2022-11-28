import java.util.*;
class Arrange{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        Word ob=new Word();
        System.out.print("Enter an unarranged word : ");
        String s=sc.next();
        int n=s.length();
        System.out.println("Arranged Word:");
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
                int k=i;String s1="";
                while(k!=0){
                    int num=k%10;
                    s1+=s.charAt(num-1);
                    k/=10;
                }
                if(ob.check(s1))
                    System.out.println(s1);
            }
        }
        sc.close();
    }
}