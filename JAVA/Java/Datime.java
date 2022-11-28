import java.util.*;
class Datime{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the year of your birth = ");
        int y1=sc.nextInt();
        System.out.print("Enter the month of your birth = ");
        int m1=sc.nextInt();
        System.out.print("Enter the date of your birth = ");
        int d1=sc.nextInt();
        System.out.print("Enter the Hours of your birth in 24 hours format = ");
        int h1=sc.nextInt();
        System.out.print("Enter the mins of your birth in 24 hours format = ");
        int mi1=sc.nextInt();
        System.out.print("Enter the current year = ");
        int y2=sc.nextInt();
        System.out.print("Enter the current month = ");
        int m2=sc.nextInt();
        System.out.print("Enter the current date = ");
        int d2=sc.nextInt();
        System.out.print("Enter the current hours in 24 hours format = ");
        int h2=sc.nextInt();
        System.out.print("Enter the current mins in 24 hours format = ");
        int mi2=sc.nextInt();
        int diffmi,diffh,diffd,diffm,diffy;
        Checkdat ob=new Checkdat();
        if(ob.checkDate(m1,d1,y1) && ob.checkTime(h2,mi2,0) &&
           ob.checkDate(m2,d2,y2) &&  ob.checkTime(h1,mi1,0)){
            if(mi2>=mi1){
                diffmi=m2-m1;
                if(h2>=h1){
                    diffh=h2-h1;
                    if(d2>=d1){
                        diffd=d2-d1;
                        if(m2>=m1){
                            diffm=m2-m1;
                            diffy=y2-y1;
                        }else{
                            diffm=(12+m2)-m1;
                            diffy=(y2-y1)-1;
                        }
                    }else{
                        diffd=(30+d2)-d1;
                        if(m2>=m1){
                            diffm=(m2-m1)-1;
                            diffy=y2-y1;
                        }else{
                            diffm=((12+m2)-m1)-1;
                            diffy=(y2-y1)-1;
                        }
                    }
                }else{
                    diffh=(24+h2)-h1;
                    if(d2>=d1){
                        diffd=(d2-d1)-1;
                        if(m2>=m1){
                            diffm=m2-m1;
                            diffy=y2-y1;
                        }else{
                            diffm=(12+m2)-m1;
                            diffy=(y2-y1)-1;
                        }
                    }else{
                        diffd=((30+d2)-d1)-1;
                        if(m2>=m1){
                            diffm=(m2-m1)-1;
                            diffy=y2-y1;
                        }else{
                            diffm=((12+m2)-m1)-1;
                            diffy=(y2-y1)-1;
                        }
                    }
                }
            }else{
                diffmi=(60+m2)-m1;
                if(h2>=h1){
                    diffh=(h2-h1)-1;
                    if(d2>=d1){
                        diffd=d2-d1;
                        if(m2>=m1){
                            diffm=m2-m1;
                            diffy=y2-y1;
                        }else{
                            diffm=(12+m2)-m1;
                            diffy=(y2-y1)-1;
                        }
                    }else{
                        diffd=(30+d2)-d1;
                        if(m2>=m1){
                            diffm=(m2-m1)-1;
                            diffy=y2-y1;
                        }else{
                            diffm=((12+m2)-m1)-1;
                            diffy=(y2-y1)-1;
                        }
                    }
                }else{
                    diffh=((24+h2)-h1)-1;
                    if(d2>=d1){
                        diffd=(d2-d1)-1;
                        if(m2>=m1){
                            diffm=m2-m1;
                            diffy=y2-y1;
                        }else{
                            diffm=(12+m2)-m1;
                            diffy=(y2-y1)-1;
                        }
                    }else{
                        diffd=((30+d2)-d1)-1;
                        if(m2>=m1){
                            diffm=(m2-m1)-1;
                            diffy=y2-y1;
                        }else{
                            diffm=((12+m2)-m1)-1;
                            diffy=(y2-y1)-1;
                        }
                    }
                }
            }
            System.out.println("The duration is "+diffy+" Years "+diffm+" Months "+diffd+" Days "+diffh+" hours "+diffmi+" mins");
        }
        else System.out.print("Wrong Input");
        sc.close();
    }
}