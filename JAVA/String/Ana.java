import java.util.*;
class Ana{
    static Scanner sc=new Scanner(System.in);
    static Ana ob=new Ana();
    boolean checkAna(String s,String s1){
        boolean b=false;
        if(s.length()<s1.length()){
            String c=s;s=s1;s1=c;
        }
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);b=false;
            for(int j=0;j<s1.length();j++){
                char ch1=s1.charAt(j);
                if(ch==ch1)
                b=true;
            }
            if(b==false)
            break;
        }
        return b;
    }
    void aIW(){
        System.out.println("Enter 2 words : ");
        String s=sc.next().toUpperCase();
        String s1=sc.next().toUpperCase();
        if(ob.checkAna(s,s1))
        System.out.println(s+" and "+s1+" are Anagrams");
        else
        System.out.println(s+" and "+s1+" are not Anagrams");
    }
    void aIS(){
        System.out.println("Enter a Sentence : ");
        sc.nextLine();
        String S=sc.nextLine().toUpperCase()+" ";
        System.out.println("Anagrams in the sentence are:");
        for(int j=0;j<S.length();){
            int k=S.indexOf(' ');
            String s=S.substring(j,k);
            S=S.substring(k+1);
            if(s.length()>0){
                StringTokenizer ST=new StringTokenizer(S);
                while(ST.hasMoreTokens()){
                    String s1=ST.nextToken();
                    if(ob.checkAna(s,s1))
                        System.out.println(s+" , "+s1);
                }
            }
        }
    }
    public static void main(String args[]){
        System.out.println("1. Anagram in words.");
        System.out.println("2. Anagram in Strings.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.aIW();
            else if(ch==2) ob.aIS();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}