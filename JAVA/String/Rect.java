import java.util.*;
class Rect{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        Word ob=new Word();
        System.out.print("Enter a String : ");
        String st=" "+sc.nextLine().trim(),s1="";
        for(int j=0;j<st.length();){
            int k=st.indexOf('.');
            String s=st.substring(j,k),s2="";
            st=st.substring(k+1);
            if(s.length()>0){
                StringTokenizer ST=new StringTokenizer(s);
                while(ST.hasMoreTokens()){
                    String w=ST.nextToken();
                    if(ob.check(w))
                        s2+=w.toLowerCase()+" ";
                    else
                        s2+=w.substring(0,1).toUpperCase()+w.substring(1).toLowerCase();
                    System.out.println("Inside "+s2);
                }
                s2=s2.substring(0,1).toUpperCase()+s2.substring(1);
                s1+=s2.trim()+". ";j=0;
                System.out.println("Outside "+s1);
                System.out.println(s1.trim());
            }
        }
        sc.close();
    }
}