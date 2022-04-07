public class Q2{
    public static void main(String[] args){
        int co = 0, ce = 0;
        for(int i=0; i<10; i++){
            int a = Integer.parseInt(args[i]);
            if(a%2 == 0) ce++;
            else co++;
        }
        System.out.println("Even Count : " + ce); System.out.println("Odd Count : " + co);
    }
}