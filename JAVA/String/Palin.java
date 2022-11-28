import java.util.*;
class Palin{
    static Scanner sc=new Scanner(System.in);
    static Palin ob=new Palin();
    String isPal(String s){
        String s1="";
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            s1=ch+s1;
        }
        if(s.equalsIgnoreCase(s1))
            return s;
        else
            return s+s1;
    }
    void pIS(){
        System.out.print("Enter a Sentence : ");
        sc.nextLine();
        String s=sc.nextLine();
        StringTokenizer st=new StringTokenizer(s);
        System.out.println("The Palindrome Words in the Sentence are :");
        while(st.hasMoreTokens()){
            String w=st.nextToken();
            if(w.equalsIgnoreCase(ob.isPal(w)))
            System.out.println(w);
        }
    }
    void pIW(){
        System.out.print("Enter a Word : ");
        String s=sc.next();
        if(s.equalsIgnoreCase(ob.isPal(s)))
            System.out.println(s+" is already a isPalindrome word.");
        else
            System.out.println(ob.isPal(s));
    }
    public static void main(String args[]){
        System.out.println("1. Palindrome in words.");
        System.out.println("2. Palindrome in Strings.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.pIW();
            else if(ch==2) ob.pIS();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}