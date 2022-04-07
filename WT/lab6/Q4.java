import java.util.Scanner;
class Q4{
    static void subtract(float x, float y){
        System.out.println("Difference : "+ (x-y));
    }
    static void subtract(int x, int y){
        System.out.println("Difference : "+ (x-y));
    }
    static void subtract(double x, double y){
        System.out.println("Difference : "+ (x-y));
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter 2 float values : ");
        float x = sc.nextFloat();
        float y = sc.nextFloat();
        subtract(x, y);
        
        System.out.print("\nEnter 2 double values : ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        subtract(a, b);

        System.out.print("\nEnter 2 int values : ");
        int p = sc.nextInt();
        int q = sc.nextInt();
        subtract(p, q);
    }
}