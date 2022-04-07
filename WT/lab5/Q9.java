import java.util.Scanner;
class Q9{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a no. : ");
        int n = sc.nextInt();
        String word = "", res = "";
        for (int m=n; m>0; m/=10) {
            switch (m%10){
                case 1: word = "one"; break;
                case 2: word = "two"; break;
                case 3: word = "three"; break;
                case 4: word = "four"; break;
                case 5: word = "five"; break;
                case 6: word = "six"; break;
                case 7: word = "seven"; break;
                case 8: word = "eight"; break;
                case 9: word = "nine"; break;
                case 0: word = "zero"; break;
                default: System.out.println("Invalid."); break;
            }
            res = word +" "+ res;
        }
        System.out.println(n+" : "+res);
    }
}