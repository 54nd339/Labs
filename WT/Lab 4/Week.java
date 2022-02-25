import java.util.*;
import java.io.*;
class Week{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        System.out.print("Enter the day no. : ");
        int m = sc.nextInt();
        if (m<1 || m>31) pw.println("Invalid day no.");
        else{
            m%=7;
            switch(m){
                case 0 : pw.println("Friday"); break;
                case 1 : pw.println("Saturday"); break;
                case 2 : pw.println("Sunday"); break;
                case 3 : pw.println("Monday"); break;
                case 4 : pw.println("Tuesday"); break;
                case 5 : pw.println("Wednesday"); break;
                case 6 : pw.println("Thursday"); break;
            }
        }
    }
}