import java.util.Scanner;
class Q5{
    static void area(float a){
        System.out.println("Area of circle : "+ (3.14*a*a));
    }
    static void area(float b, float h){
        System.out.println("Area of triangle : "+ (0.5*b*h));
    }
    static void area(double a){
        System.out.println("Area of square : "+ (a*a));
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Area of circle");
        System.out.println("2. Area of triangle");
        System.out.println("3. Area of square");
        System.out.println("0. Exit");
        while(true){
            System.out.print("\nEnter your choice : ");
            int ch = sc.nextInt();
            if(ch == 1){
                System.out.print("\nEnter Radius of circle : ");
                float r = sc.nextFloat(); area(r);
            }
            else if(ch == 2){
                System.out.print("\nEnter breadth n height of triangle : ");
                float b = sc.nextFloat();
                float h = sc.nextFloat(); area(b, h);
            }
            else if(ch == 3){
                System.out.print("\nEnter length of a side of square : ");
                double a = sc.nextDouble(); area(a);
            }
            else if(ch == 0) break;
            else System.out.println("Wrong Choice.");
        }
    }
}