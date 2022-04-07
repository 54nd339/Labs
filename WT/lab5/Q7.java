import java.util.Scanner;
class Q7{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a no. : ");
        int n = sc.nextInt(), sum=0;
        for (int m=n; m>0; m/=10)
            sum += m%10;
        System.out.println("Sum of Digits : "+sum);
    }
}