import java.util.*;
class Marks{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter Your Class ");
        int cl=sc.nextInt();
        double max=0,sub=0,E1=0,E2=0,M=0,SS=0,HC=0,G=0,AVM=0,GK=0,H=0,LNW=0,O=0,Com=0,Sc=0,P=0,C=0,B=0,MSc=0;
        if(cl>=1 && cl<=10){
            System.out.print("Enter Your max mark of each subject ");
            max=sc.nextInt();
            System.out.println("");
            System.out.print("Marks in English 1: ");
            E1=sc.nextDouble();
            System.out.print("Marks in English 2: ");
            E2=sc.nextDouble();
            System.out.print("Marks in Mathematics: ");
            M=sc.nextDouble();
            System.out.print("Marks in Abacus/Vedic Maths: ");
            AVM=sc.nextDouble();
            System.out.print("Marks in Computer: ");
            Com=sc.nextDouble();
            System.out.print("Marks in Moral Science: ");
            MSc=sc.nextDouble();sub+=6;
        }
        if(cl>=1 && cl<=8){
            System.out.print("Marks in General Knowledge: ");
            GK=sc.nextDouble();
            System.out.print("Marks in Hindi: ");
            H=sc.nextDouble();
            System.out.print("Marks in LNW: ");
            LNW=sc.nextDouble();
            System.out.print("Marks in Odia/Alternative English: ");
            O=sc.nextDouble();sub+=4;
        }
        if(cl>=1 && cl<=6){
            System.out.print("Marks in Science: ");
            Sc=sc.nextDouble();sub++;
        }
        if(cl>=1 && cl<=5){
            System.out.print("Marks in Social Studies: ");
            SS=sc.nextDouble();sub++;
        }
        if(cl>=6 && cl<=10){
            System.out.print("Marks in History/Civics: ");
            HC=sc.nextDouble();
            System.out.print("Marks in Geography: ");
            G=sc.nextDouble();sub+=2;
        }
        if(cl>=7 && cl<=10){
            System.out.print("Marks in Physics: ");
            P=sc.nextDouble();
            System.out.print("Marks in Chemistry: ");
            C=sc.nextDouble();
            System.out.print("Marks in Biology: ");
            B=sc.nextDouble();sub+=3;
        }
        if(cl>=9 && cl<=10){
            System.out.print("Marks in Hindi/Odia: ");
            O=sc.nextDouble();sub++;
        }
        if(sub==0) System.out.print("Input Error");
        else{
            System.out.println();
            double tot=E1+E2+M+SS+HC+G+AVM+GK+H+LNW+O+Com+Sc+P+C+B+MSc;
            System.out.println("Total: "+tot+"/"+(sub*max));
            double per=(tot/(sub*max))*100;
            System.out.println("Percentage: "+per);
        }
        sc.close();
    }
}