import java.util.*;
class Time{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        Checkdat ob=new Checkdat();
        System.out.print("Enter the Arrival Hours in 24 hours format = ");
        int ah=sc.nextInt();
        System.out.print("Enter the Arrival mins in 24 hours format = ");
        int am=sc.nextInt();
        System.out.print("Enter the Departure Hours in 24 hours format = ");
        int dh=sc.nextInt();
        System.out.print("Enter the Departure mins in 24 hours format = ");
        int dm=sc.nextInt();
        if(ob.checkTime(ah,am,0) && ob.checkTime(dh,dm,0)){
            if(ah>dh) dh+=24;
            if(dm>=am){
                int diffh=dh-ah;
                int diffm=dm-am;
                System.out.println("The duration is "+diffh+" hours and "+diffm+" mins");
            }else{
                int m=(60+dm)-am;
                int h=(dh-ah)-1;
                System.out.println("The duration is "+h+" hours and "+m+" mins");
            }
        }
        else System.out.print("Wrong Input");
        sc.close();
    }
}