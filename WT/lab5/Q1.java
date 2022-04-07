import java.util.Scanner;
class Q1{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a 3 digit no. : ");
        int n = sc.nextInt();
        if(n/100 == n%10)
            System.out.println(n+" is Palindrome.");
        else
            System.out.println(n+" is NOT Palindrome.");
    }
}