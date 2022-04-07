import java.util.Scanner;
class Q2{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a character : ");
        int n = sc.next().charAt(0);
        if(n>=97 && n<=122)
            System.out.println((char)n+"->"+(char)(n-32));
        else if(n>=65 && n<=90)
            System.out.println((char)n+"->"+(char)(n+32));
        else
            System.out.println("Invalid Alphabet.");
    }
}