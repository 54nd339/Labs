import java.util.*;
public class Q1 {
	public static void main (String[] args) {
        Vector<Integer> v1 = new Vector<>();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter elements (-1 to exit) : ");
        while(true){
            int n = sc.nextInt();
            if(n == -1)
                break;
            v1.add(n);
        }
        System.out.println("Original Vector : "+v1);
        
        Vector<Integer> v2 = new Vector<>(v1);
        System.out.println("Copied Vector : "+v2);			
	}
}