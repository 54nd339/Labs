import java.util.*;
class Name{
    static Scanner sc=new Scanner(System.in);
    static Name ob=new Name();
    void shor(){
        System.out.print("Enter a String : ");
        sc.nextLine();
        String s=" "+sc.nextLine().trim(),s1="";int i=0;
        for(i=0;i<s.lastIndexOf(" ");i++){
            char ch=s.charAt(i);
            if(ch==' ')
            s1+=Character.toUpperCase(s.charAt(i+1))+"."+" ";
        }
        String s2=s1+s.substring(i+1);
        System.out.print(s2);
    }
    void del(){
        System.out.print("Enter a String : ");
        sc.nextLine();
        String s=sc.nextLine().trim();
        String s1=s.substring(0,s.indexOf(" "))+s.substring(s.lastIndexOf(" "));
        System.out.print(s1);
    }
    public static void main(String args[]){
        System.out.println("1. Shorten a String.");
        System.out.println("2. Delete a String.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.shor();
            else if(ch==2) ob.del();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}