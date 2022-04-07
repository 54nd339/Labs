import java.util.Scanner;
import Marketing.Sales;
public class Q4 {
    public static void main(String[] args) {
        Sales ob = new Sales();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Basic : ");
        float basic = sc.nextFloat();
        ob.display(basic);
    }
}