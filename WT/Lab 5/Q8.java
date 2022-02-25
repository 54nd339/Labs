import java.util.*;
class Q8{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a no. : ");
        int n = sc.nextInt(), res = 0;
        int cnt[] = {0,0,0,0,0,0,0,0,0,0};
		while (n>0) {
            cnt[n % 10]++;
            n/=10;
		}
        for (int i=0; i<cnt.length; i++)
            if (cnt[i] >= 1) res++;
        System.out.println("No. of unique didgits : "+res);
	}
}