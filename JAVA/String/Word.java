import java.util.*;
import java.io.*;
class Word{
    boolean check(String s){
        try{
            Scanner sc=new Scanner(new File("words.txt"));
            while(sc.hasNext()){
                if(sc.next().equalsIgnoreCase(s))
                    return true;
            }
        }catch(IOException e){
            System.out.println("error encountered:");
            System.out.println(e);
        }
        return false;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        Word ob=new Word();
        System.out.print("Enter a word : ");
        String s=sc.next();
        if(ob.check(s))
        System.out.print(s+" is a word");
        else
        System.out.println(s+" is not a word");
        sc.close();
    }
}