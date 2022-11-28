import java.util.*;
class Checkdat{
    static Scanner sc=new Scanner(System.in);
    static Checkdat ob=new Checkdat();
    static int d,m,y,a,h,mi,s;
    boolean dat(int n){
        if(d<=n && d>0)
        return true;
        else
        return false;
    }
    boolean checkDate(int d,int m,int y){
        if(m<=12 && m>0){
            if(m==4 || m==6 || m==9 || m==11)
            a=30;
            else if(m==2){
                if((y%4==0 && y%100!=0)||y%400==0)
                a=29;
                else
                a=28;
            }
            else
            a=31;
            if(ob.dat(a))
            return true;
            else
            return false;
        }
        else
        return false;
    }
    boolean checkTime(int h,int mi,int s){
        if(h<=24 && mi<=60 && s<=60 && s>=0 && h>0 && mi>0)
            return true;
        else 
            return false;
    }
    public static void main(String args[]){
        System.out.println("1. Check Time");
        System.out.println("2. Check Date");
        System.out.println("0. Exit");
        System.out.print("Enter your Choice : ");
        int n=sc.nextInt();
        while(n!=0){
            if(n==1){
                int hour,min,sec;
                System.out.print("Enter \"Hour Min Sec\" : ");
                hour=sc.nextInt();
                min=sc.nextInt();
                sec=sc.nextInt();
                if(ob.checkTime(hour,min,sec)) System.out.println("Valid");
                else System.out.println("Invalid");
            } 
            else if(n==2){
                int date,mon,year;
                System.out.print("Enter \"Date Month Year\" : ");
                date=sc.nextInt();
                mon=sc.nextInt();
                year=sc.nextInt();
                if(ob.checkTime(date,mon,year)) System.out.println("Valid");
                else System.out.println("Invalid");
            }
            else{
                System.out.print("Wrong Input. Enter another choice : ");
                n=sc.nextInt();
            }
            System.out.print("\nEnter any choice to continue : ");
            n=sc.nextInt();
        }
    }
}