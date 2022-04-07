import java.util.Scanner;
public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter String 1 : ");
        String s1 = sc.next();
        System.out.print("Enter String 2 : ");
        String s2 = sc.next();
        String out = s1+s2;
        System.out.println("Concatenated String : "+out);
        int n = out.length();
        System.out.println("Substring 1 : "+out.substring(0,(int)(n/4)));
        System.out.println("Substring 2 : "+out.substring((int)(n/4),(int)(n/2)));
        System.out.println("Substring 3 : "+out.substring((int)(n/2),(int)(3*n/4)));
        System.out.println("Substring 4 : "+out.substring((int)(3*n/4))); 
    }
}