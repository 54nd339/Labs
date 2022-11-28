import java.util.*;
class Lol{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a String : ");
        String s=sc.nextLine();
        for(int i=0;i<s.length()-1;i++){
            for(int j=i+3;j<=s.length();j++){
                String s1=s.substring(i,j),s2="";
                System.out.println("S1 : "+s1);
                for(int k=0;k<s1.length();k++){
                    char ch=s1.charAt(k);
                    s2=ch+s2;
                    System.out.println("S2 : "+s2);
                }
                if(s1.equalsIgnoreCase(s2))
                System.out.println("Out : "+s2);
            }
        }
        sc.close();
    }
}