import java.util.*;
class Happy{
    static Scanner sc=new Scanner(System.in);
    static Happy ob=new Happy();
    boolean isHap(String st){
        String s1="";
        for(int i=0;i<st.length();i++){
            char ch=st.charAt(i);
            s1+=((int)ch-64);
        }
        long n=Long.valueOf(s1);
        long s=n;
        while(s>9){
            n=s;s=0;
            while(n!=0){
                long r=n%10;
                s=s+r*r;n/=10;
            }
        }
        if(s==1)
            return true;
        else
            return false;
    }
    void hIW(){
        System.out.print("Enter a Word : ");
        String s=sc.next();
        if(ob.isHap(s.toUpperCase()))
            System.out.println(s+" is a Happy Word");
        else
            System.out.println(s+" is not a Happy Word");
    }
    void hIS(){
        System.out.print("Enter a Sentence : ");
        sc.nextLine();
        String s=sc.nextLine();
        StringTokenizer st=new StringTokenizer(s);
        System.out.println("The Happy Words in the Sentence are:");
        while(st.hasMoreTokens()){
            String w=st.nextToken();
            if(ob.isHap(w))
            System.out.println(w);
        }
    }
    public static void main(String args[]){
        System.out.println("1. Happy in words.");
        System.out.println("2. Happy in Strings.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.hIW();
            else if(ch==2) ob.hIS();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}