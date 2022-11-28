import java.util.*;
class Date{
    static Scanner sc=new Scanner(System.in);
    static Date ob=new Date();
    String dat(int n){
        String month[]={"","January","February","March","April","May","June","July",
                        "August","September","October","November","December"};
        int dm[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        int y=n%10000,d=n/10000;
        if(d>365){
            while(d>365){
                y++;
                if(y%4==0){
                    dm[2]=29;
                    d-=366;
                }
                else{
                    dm[2]=28;
                    d-=365;
                }
            }
        }
        else{
            if(y%4==0)
                dm[2]=29;
            else
                dm[2]=28;
        }
        int c=0,i=0;
        for(i=1;i<=12;i++){
            c+=dm[i];
            if(c>d)
            break;
        }
        c=0;
        for(int j=1;j<i;j++)
            c+=dm[j];
        int date=d-c;
        if(date==0)
        return (dm[i-1]+" "+month[i-1]+" "+y);
        else
        return (date+" "+month[i]+" "+y);
    }
    int accept(){
        System.out.print("Enter the day no. : ");
        int d=sc.nextInt();
        System.out.print("Enter the year : ");
        int y=sc.nextInt();
        String s=""+d+y;
        int m=Integer.parseInt(s);
        while(m<10000||m%10000<1900||m%10000>3000){
            System.out.print("Enter a no. not less than 5 digit : ");
            m=sc.nextInt();
        }
        return m;
    }
    public static void main(String args[]){
        int m=ob.accept();
        System.out.println("Date : "+ob.dat(m));
        System.out.print("Enter a no. : ");
        int n=sc.nextInt();
        System.out.println("New Date : "+ob.dat(m+n*10000));
    }
}