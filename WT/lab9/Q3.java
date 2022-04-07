import java.util.Scanner;
public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Case Change.");
        System.out.println("2. String Reverse.");
        System.out.println("3. Compare Strings.");
        System.out.println("4. Insert one string into another.");
        System.out.println("0. Exit");
        while (true) {
            System.out.print("\nEnter your choice : ");
            int ch = sc.nextInt();
            if(ch == 1){
                System.out.print("Enter a string : ");
                String s = sc.next();
                System.out.println("In UpperCase : "+s.toUpperCase());
                System.out.println("In LowerCase : "+s.toLowerCase());
            }
            else if(ch == 2){
                System.out.print("Enter a string : ");
                String s = sc.next();
                System.out.print("Reversed String : ");
                char[] Sarray = s.toCharArray();
                for (int i = Sarray.length - 1; i >= 0; i--)
                    System.out.print(Sarray[i]);
                System.out.println("");
            }
            else if(ch == 3){
                System.out.print("Enter a string : ");
                String s1 = sc.next();
                System.out.print("Enter another string : ");
                String s2 = sc.next();
                if(s1.compareTo(s2) == 0)
                    System.out.println("Matched.");
                else
                    System.out.println("Mismatched.");
            }
            else if(ch == 4){
                System.out.print("Enter String1 : ");
                sc.nextLine();
                String s = sc.nextLine();
                System.out.print("Enter String2 : ");
                String ss = sc.next();
                int ind = s.indexOf(' ');
                String out = s.substring(0,ind)+" "+ss+s.substring(ind);
                System.out.println("Output : "+out);
            }
            else if(ch == 0) break;
            else System.out.println("Invalid choice.");
        }
    }
}