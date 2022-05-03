import java.util.*;
public class Q4 {
    static Vector<Integer> r = new Vector<>();
    static Vector intoar(int n){
        Vector<Integer> num = new Vector<>();
        while(n != 0){
            num.add(0, n%10);
            n /= 10;
        }
        return num;
    }
    static Vector conv(int num, int den){
        Vector<Integer> q = new Vector<>(intoar((int)(num/den)));
        int rem = num % den;
        for(int i = 0; i < 10 && rem!=0; i++){
            r.add((int)((rem*10)/den));
            rem = (rem*10)%den;
        }
        System.out.println("Quotient : "+q);
        System.out.println("Decimals : "+r);
        q.addAll(r); return q;
    }
    static int mul(Vector<Integer> v1, int n){
        Vector<Integer> v2 = new Vector<>(Q4.intoar(n));
        int l1 = v1.size(), l2 = v2.size();
        if (l1 == 0 || l2 == 0)
            return 0;

        int res[] = new int[l1 + l2];
        int in1 = 0, in2 = 0;
        for (int i = l1 - 1; i >= 0; i--) {
            int carry = 0, sum = 0; in2 = 0;
            int n1 = v1.get(i);
            for (int j = l2 - 1; j >= 0; j--) {
                int n2 = v2.get(j);
                sum = n1 * n2 + res[in1 + in2] + carry;
                carry = sum / 10;
                res[in1 + in2] = sum % 10;
                in2++;
            }
            if (carry > 0)
                res[in1 + in2] += carry;
            in1++;
        }

        int i = res.length - 1, j = r.size();
        while (i >= 0 && res[i] == 0)
            i--;
        if (i == -1)
            return 0;

        int sum = 0; r.clear();
        while (i >= 0){
            if(i >= j)
                sum = sum*10 + res[i--];
            else
                r.add(res[i--]);
        }

        return sum;
    }
    static Vector tohex(){
        int in = 0;
        Vector<String> res = new Vector<>();
        for (int i = 0; i < r.size(); i++){
            in = Q4.mul(r, 16);
            if (in > 9)
               res.add(""+(char)(55 + in));
            else
                res.add(""+in);
        }
        return res;
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Num, Den : ");
        int num = sc.nextInt();
        int den = sc.nextInt();
        Vector<Integer> res = new Vector<>(Q4.conv(num, den));

        System.out.print("\nEnter a no. : ");
        int n = sc.nextInt();
        int q = Q4.mul(res, n);

        System.out.println("Whole Number part : "+q);
        System.out.println("Decimal part : "+r);

        Vector<String> Hex = new Vector<>(Q4.tohex());
        System.out.println("\nHex : "+Hex); 
    }
}
