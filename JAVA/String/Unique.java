import java.util.*;
class Unique{
    static Scanner sc=new Scanner(System.in);
    static Unique ob=new Unique();
    String isUniq(String s){
        s=s.toLowerCase();String st="";char cha=' ';
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);int c=0;
            for(int j=0;j<st.length();j++){
                cha=st.charAt(j);
                if(cha==ch)
                    c=1;
            }
            if(c==0)
                st+=ch;
        }
        return st;
    }
    void uIS(){
        System.out.print("Enter a Sentence: ");
        sc.nextLine();
        String s=sc.nextLine();
        StringTokenizer st=new StringTokenizer(s);
        System.out.println("The Unique Words in the Sentence are:");
        while(st.hasMoreTokens()){
            String w=st.nextToken();
            if(w.equalsIgnoreCase(ob.isUniq(w)))
            System.out.println(w);
        }
    }
    void uIW(){
        System.out.print("Enter a Word: ");
        sc.nextLine();
        String s=sc.next();
        if(s.equalsIgnoreCase(ob.isUniq(s)))
            System.out.println(s+" is already an Unique Word");
        else
            System.out.print(ob.isUniq(s));
    }
    public static void main(String args[]){
        System.out.println("1. Unique in words.");
        System.out.println("2. unique in Strings.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.uIW();
            else if(ch==2) ob.uIS();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}