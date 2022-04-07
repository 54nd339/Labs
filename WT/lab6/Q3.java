import java.util.Scanner;
class Box{
    float l, b, h;
    Box(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter dimension of box : ");
        l = sc.nextFloat();
        b = sc.nextFloat();
        h = sc.nextFloat();
    }
    void volume(){
        System.out.println("Volume : "+ (l*b*h));
    }
}
public class Q3{ //Demo class
    public static void main(String[] args){
        Box box = new Box();
        box.volume();
    }
}