import java.util.Scanner;
class Week{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the day no. : ");
        int m = sc.nextInt();
        if (m<1 || m>31) System.out.println("Invalid day no.");
        else{
            m %= 7;
            switch(m){
                case 0 : System.out.println("Friday"); break;
                case 1 : System.out.println("Saturday"); break;
                case 2 : System.out.println("Sunday"); break;
                case 3 : System.out.println("Monday"); break;
                case 4 : System.out.println("Tuesday"); break;
                case 5 : System.out.println("Wednesday"); break;
                case 6 : System.out.println("Thursday"); break;
            }
        }
    }
}