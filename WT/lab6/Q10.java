import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class Plate{
    float length, width;
    Plate(){
        System.out.print("Enter length : ");
        length = Input.sc.nextFloat();
        System.out.print("Enter width : ");
        width = Input.sc.nextFloat();
    }
    void display(){
        System.out.println("Length : "+length);
        System.out.println("Width : "+width);
    }
}
class Box extends Plate{
    float height;
    Box(){
        System.out.print("Enter height : ");
        height = Input.sc.nextFloat();
    }
    void display(){
        super.display();
        System.out.println("Height : "+height);
    }
}
class W_Box extends Box{
    float thickness;
    W_Box(){
        System.out.print("Enter thickness : ");
        thickness = Input.sc.nextFloat();
    }
    void display(){
        super.display();
        System.out.println("Thickness : "+thickness);
    }
}
public class Q10{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("1. Plate\n2. Box\n3. Wooden Box\nEnter Your option : ");
        int ch = sc.nextInt();
        if (ch == 1) {
            Plate plate = new Plate();
            plate.display();
        }
        else if (ch == 2) {
            Box box = new Box();
            box.display();
        }
        else if (ch == 3) {
            W_Box wbox = new W_Box();
            wbox.display();
        }
        else
            System.out.println("Invalid Option Entered.");
    }
}