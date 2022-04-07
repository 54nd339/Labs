import java.util.Scanner;
class Marks{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your marks : ");
        int m = sc.nextInt();
        if(m>=90 && m<=100)
            System.out.println("O Grade.");
        else if(m>=80 && m<90)
            System.out.println("E Grade.");
        else if(m>=70 && m<80)
            System.out.println("A Grade.");
        else if(m>=60 && m<70)
            System.out.println("B Grade.");
        else if(m>=50 && m<60)
            System.out.println("C Grade.");
        else if(m>=40 && m<50 )
            System.out.println("D Grade.");
        else if(m>=0 && m<40)
            System.out.println("F Grade");
        else
            System.out.println("Invalid Marks.");
    }
}