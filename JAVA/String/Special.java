import java.util.*;
class Special{
    static Scanner sc=new Scanner(System.in);
    static Special ob=new Special();
    boolean isSpec(String s){
        s=s.toLowerCase();
        if(s.charAt(0)==s.charAt(s.length()-1))
            return true;
        else
            return false;
    }
    void sIS(){
        System.out.print("Enter a Sentence: ");
        sc.nextLine();
        String s=sc.nextLine();
        StringTokenizer st=new StringTokenizer(s);
        System.out.println("The Special Words in the Sentence are:");
        while(st.hasMoreTokens()){
            String w=st.nextToken();
            if(ob.isSpec(w))
            System.out.println(w);
        }
    }
    void sIW(){
        System.out.print("Enter a Word: ");
        sc.nextLine();
        String s=sc.next();
        if(ob.isSpec(s))
            System.out.println(s+" is a Special Word");
        else
            System.out.println(s+" is not a Special Word");
    }
    public static void main(String args[]){
        System.out.println("1. special in words.");
        System.out.println("2. special in Strings.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.sIW();
            else if(ch==2) ob.sIS();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}