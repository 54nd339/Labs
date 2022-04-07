import java.util.Scanner;
class Q3{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter 2 characters : ");
        int n = sc.next().charAt(0);
        int m = sc.next().charAt(0);
        if(m > n)
            System.out.println((char)n+","+(char)m);
        else 
            System.out.println((char)m+","+(char)n);
    }
}