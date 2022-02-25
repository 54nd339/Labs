import java.util.*;
import java.io.*;
class Marks{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        System.out.print("Enter your marks : ");
        int m = sc.nextInt();
        if(m>=90 && m<=100)
            pw.println("O Grade.");
        else if(m>=80 && m<90)
            pw.println("E Grade.");
        else if(m>=70 && m<80)
            pw.println("A Grade.");
        else if(m>=60 && m<70)
            pw.println("B Grade.");
        else if(m>=50 && m<60)
            pw.println("C Grade.");
        else if(m>=40 && m<50 )
            pw.println("D Grade.");
        else if(m>=0 && m<40)
            pw.println("F Grade");
        else
            pw.println("Invalid Marks.");
    }
}