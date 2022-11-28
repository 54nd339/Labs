import java.util.*;
class Sen{
    static Scanner sc=new Scanner(System.in);
    static Sen ob=new Sen();
    void revSen(String s){
        s=s.trim()+" ";String w="",s2=" ";
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            if(ch!=' ')
                w+=ch;
            else{
                s2=w+" "+s2;
                w="";
            }
        }
        System.out.println(s2.trim());
    }
    void reverse(){
        System.out.print("Enter a Sentence : ");
        sc.nextLine();
        String s=sc.nextLine();
        Sen ob=new Sen();
        ob.revSen(s);
    }
    void arr(){
        System.out.print("Enter a Sentence : ");
        sc.nextLine();
        String s=sc.nextLine().trim().toLowerCase(),w="",s2="";
        System.out.println("1.Ascending");
        System.out.println("2.Descending");
        System.out.print("Enter your option : ");
        int ch=sc.nextInt();
        StringTokenizer st1=new StringTokenizer(s);
        int c=0,i=0;
        while(st1.hasMoreTokens()){
            c++;s2=st1.nextToken();
        }
        String ar[]=new String[c];
        StringTokenizer st=new StringTokenizer(s);
        for(i=0;i<ar.length;i++)
            ar[i]=st.nextToken();
        for(int j=0;j<ar.length-1;j++)
            for(i=0;i<ar.length-1;i++){
                if(ar[i].compareTo(ar[i+1])>0){
                    w=ar[i];
                    ar[i]=ar[i+1];
                    ar[i+1]=w;
                }
            }
        s2="";
        if(ch==1)
            for(i=0;i<ar.length;i++)
                s2+=" "+ar[i];
        else if (ch==2)
            for(i=0;i<ar.length;i++)
                s2=ar[i]+" "+s2;
        else
            s2="Wrong Input";
        System.out.println(s2.trim());
    }
    void freq(){
        System.out.print("Enter a Sentence: ");
        sc.nextLine();
        String s=sc.nextLine();int c=0,i=0;
        StringTokenizer st=new StringTokenizer(s);
        StringTokenizer st1=new StringTokenizer(s);
        while(st.hasMoreTokens()){
            c++;st.nextToken();
        }
        String ar[]=new String[c];
        while(st1.hasMoreTokens()){
            ar[i]=st1.nextToken();i++;
        }
        for(int j=0;j<ar.length-1;j++)
            for(int k=j+1;k<ar.length;k++)
                if(ar[j].equalsIgnoreCase(ar[k]))
                    ar[k]="";
        for(int j=0;j<ar.length;j++){
            i=0;StringTokenizer st2=new StringTokenizer(s);
            int count=0;
            while(st2.hasMoreTokens()){
                if(ar[j].equalsIgnoreCase(st2.nextToken()))
                count++;
            }
            if(!ar[j].equals(""))
                System.out.println("The frequency of "+ar[j]+" is "+count);
        }
    }
    public static void main(String args[]){
        System.out.println("1. Reverse a Sentence.");
        System.out.println("2. Arrange a Sentence.");
        System.out.println("3. Frequency of a word.");
        System.out.println("0. Exit.");
        System.out.print("Enter your choice : ");
        int ch=sc.nextInt();
        while(ch!=0){
            if(ch==1) ob.reverse();
            else if(ch==2) ob.arr();
            else if(ch==3) ob.freq();
            else System.out.print("Wrong Input. Try Again.");
            System.out.print("Enter 0 to Exit and others to continue : ");
            ch=sc.nextInt();
        }
    }
}