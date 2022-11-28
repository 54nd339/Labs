import java.util.*;
class Num{
    String num(long n){
        long na[]=new long[3];
        String word[]={"One","Two","Three","Four","Five","Six","Seven","Eight"
                      ,"Nine","Ten","Eleven","Twelve","Thirteen","Fourteen"
                      ,"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
                      ,"Twenty","Thirty","Forty","Fifty","Sixty","Seventy"
                      ,"Eighty","Ninety","Hundred"};
        long m=n,i=3;String s="";
        while(m!=0){
            na[(int)--i]=m%10;
            m/=10;
        }
        if(na[0]!=0)
            s+=(word[(int)na[0]-1]+" "+word[27]+" ");
        if(na[1]!=0){
            if(na[1]>=2){
                s+=(word[(int)na[1]+17]+" ");
                if(na[2]!=0)
                    s+=(word[(int)na[2]-1]);
            }
            if(na[1]==1)
                s+=(word[(int)na[2]+9]);
        }
        else if(na[1]==0&&na[2]!=0)
            s+=(word[(int)na[2]-1]);
        return s;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        Num ob=new Num();
        long na[]=new long[5];
        String word[]={"","Thousand","Million","Billion","Trillion"};
        System.out.print("Enter a no. (Max. 15 digits) : ");
        long n=sc.nextLong();
        long m=n,i=5,k=0;String s="";
        while(m!=0){
            na[(int)--i]=m%1000;
            m/=1000;k++;
        }
        for(long j=0;j<na.length;j++)
            if(na[(int)j]!=0){
            s+=(ob.num(na[(int)j])+" "+word[(int)k-1]+" ");k--;}
        System.out.println(s);
        sc.close();
    }
}