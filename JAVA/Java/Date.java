import java.util.*;
class Date{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the year of your birth = ");
        int y1=sc.nextInt();
        System.out.print("Enter the month of your birth = ");
        int m1=sc.nextInt();
        System.out.print("Enter the date of your birth = ");
        int d1=sc.nextInt();
        System.out.print("Enter the current year = ");
        int y2=sc.nextInt();
        System.out.print("Enter the current month = ");
        int m2=sc.nextInt();
        System.out.print("Enter the current date = ");
        int d2=sc.nextInt();int diffd,diffm,diffy;
        Checkdat ob=new Checkdat();
        if(ob.checkDate(m1,d1,y1) && ob.checkDate(m2,d2,y2)){
            if(d2>=d1){
                diffd=d2-d1;
                if(m2>=m1){
                    diffm=m2-m1;
                    diffy=y2-y1;
                }else{
                    diffm=(12+m2)-m1;
                    diffy=(y2-y1)-1;
                }
                System.out.println("The duration is "+diffy+" years and "+diffm+" months "+diffd+" days");
            }else{
                diffd=(30+d2)-d1;
                if(m2>=m1){
                    diffm=(m2-m1)-1;
                    diffy=y2-y1;
                }else{
                    diffm=((12+m2)-m1)-1;
                    diffy=(y2-y1)-1;
                }
                System.out.println("The duration is "+diffy+" years and "+diffm+" months "+diffd+" days");
            }
        }
        else System.out.print("Wrong Input");
        sc.close();
    }
}