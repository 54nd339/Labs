import java.util.Scanner;
class Q10{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a no. : ");
        int l = 0, s = 9;
        for (int n=sc.nextInt(); n>0; n/=10){
            int r = n%10;
            l = (l>r) ? l : r;
            s = (r>s) ? s : r;
        }
        System.out.println(l+" "+s);
    }
}