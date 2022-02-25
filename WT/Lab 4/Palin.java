import java.util.*;
class Palin{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a no. : ");
        int n = sc.nextInt();
        int m = n, s = 0;
        while(n!=0){
            int r = n%10;
            s = s*10 + r;
            n /= 10;
        }
        if(s == m)
            System.out.println(m+" is a Palindrome");
        else
            System.out.println(m+" is Not a Palindrome");
    }
}