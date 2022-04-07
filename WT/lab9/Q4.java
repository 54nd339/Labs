import java.util.Scanner;
public class Q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name of Student 1 : ");
        String name1 = sc.nextLine();
        System.out.print("Enter Name of Student 2 : ");
        String name2 = sc.nextLine();
        int p1 = name1.lastIndexOf(' ');
        int p2 = name2.lastIndexOf(' ');
        String ns1 = name1.substring(0, p1) + name2.substring(p2, name2.length());
        String ns2 = name2.substring(0, p2) + name1.substring(p1, name1.length());
        System.out.println("\nNew names are : ");
        System.out.println(ns1);
        System.out.println(ns2);
    }
}