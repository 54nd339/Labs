import java.util.*;
class PL{
    static Scanner sc=new Scanner(System.in);
    static PL ob=new PL();
    String toPL(String s){
        s=s.toLowerCase();int i;
        for(i=0;i<s.length()-1;i++){
            char ch=s.charAt(i);
            if(ch=='a' || ch=='e' || ch=='o' || ch=='i' || ch=='u')
            break;
        }
        String p=s.substring(i)+s.substring(0,i)+"ay";
        return p;
    }
    void pIW(){
        System.out.print("Enter a String : ");
        String s=sc.nextLine();
        System.out.println("PigLatin form of "+s+" is "+ob.toPL(s));
    }
    void pIS(){
        System.out.print("Enter a Sentence: ");
        sc.nextLine();
        String s=sc.nextLine(),s1="";
        StringTokenizer st=new StringTokenizer(s);
        while(st.hasMoreTokens())
            s1+=ob.toPL(st.nextToken())+" ";
        System.out.println(s1.trim());
    }
    public static void main(String args[]){
        System.out.println("1. Pig Latin in words.");
        System.out.println("2. Pig Latin in Strings.");
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