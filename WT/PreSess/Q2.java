import java.util.*;
public class Q2 {
	public static void main (String[] args) {
        Vector<Integer> v = new Vector<>();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter elements (-1 to exit) : ");
        while(true){
            int n = sc.nextInt();
            if(n == -1)
                break;
            v.add(n);
        }
        System.out.println("Entered Vector : "+v);

        System.out.print("Vector in reverse : ");
		for (int i = v.size() - 1; i >= 0; i--) 
			System.out.print(v.get(i)+" ");
	}
}