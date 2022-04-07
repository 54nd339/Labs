import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class Sheet{
    float length, breadth;
    Sheet(){
        System.out.print("Enter length : ");
        length = Input.sc.nextFloat();
        System.out.print("Enter breadth : ");
        breadth = Input.sc.nextFloat();
    }
    float area(){
        return length*breadth;
    }
}
class Box extends Sheet{
    float height;
    Box(){
        System.out.print("Enter height : ");
        height = Input.sc.nextFloat();
    }
    float vol(){
        return super.area()*height;
    }
}
public class Q9{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("1. Box\n2. Sheet\nEnter Your option : ");
        int ch = sc.nextInt();
        if (ch == 1) {
            Box box = new Box();
            System.out.println("Price :"+box.vol()*60);
        }
        else if (ch == 2) {
            Sheet sheet = new Sheet();
            System.out.println("Price :"+sheet.area()*40);
        }
        else
            System.out.println("Invalid Option Entered.");
    }
}