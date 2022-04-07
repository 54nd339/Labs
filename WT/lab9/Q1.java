import java.util.Scanner;
public class Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Full name : ");
        String s = sc.nextLine();
        System.out.print("Enter Middle name : ");
        String ss = sc.next();
        int ind = s.indexOf(' ');
        String out = s.substring(0,ind)+" "+ss+s.substring(ind);
        System.out.println("Output : "+out);
    }
}