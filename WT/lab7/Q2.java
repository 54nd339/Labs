import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
interface Motor {
    final float capacity = 10;
    void run();
    void consume();
}
class Washing_Machine implements Motor {
    int consumable;
    Washing_Machine(){
        System.out.print("Enter How much consumable : ");
        consumable = Input.sc.nextInt();
    }
    public void run(){
        System.out.println("Washing Machine is running.");
    }
    public void consume(){
        if(consumable <= capacity)
            System.out.print("Washing Machine consumed : "+consumable);
        else
            System.out.println("Max Capacity reached.");
    }
}
public class Q2 {
    public static void main(String[] args) {
        Washing_Machine ob = new Washing_Machine();
        ob.run(); ob.consume();
    }
}