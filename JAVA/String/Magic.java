import java.util.*;
class Magic{
    static Scanner sc=new Scanner(System.in);
    static Magic ob=new Magic();
    boolean isMagi(String st){
        boolean b=false;int i=0;
        for(i=0;i<st.length()-1;i++){
            if((int)st.charAt(i)+1==(int)st.charAt(i+1)){
                b=true;break;
            }
        }
        return b;
    }
    void mIW(){
        System.out.print("Enter a Word : ");
        String s=sc.next();
        if(ob.isMagi(s.toUpperCase()))
            System.out.println(s+" is a Magic Word");
        else
            System.out.println(s+" is not a Magic Word");
    }
    void mIS(){
        System.out.print("Enter a Sentence : ");
        sc.nextLine();
        String s=sc.nextLine();
        StringTokenizer st=new StringTokenizer(s);
        System.out.println("The Magic Words in the Sentence are : ");
        while(st.hasMoreTokens()){
            String w=st.nextToken();
            if(ob.isMagi(w))
            System.out.println(w);
        }
    }
    public static void main(String args[]){
        System.out.println("1. Magic in words.");
        System.out.println("2. Magic in Strings.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.mIW();
            else if(ch==2) ob.mIS();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}