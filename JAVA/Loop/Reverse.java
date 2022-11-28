import java.util.*;
class Reverse{
    void revStr(String s){
        String s1="";
        for(int j=s.length()-1;j>=0;j--){
            char ch1=s.charAt(j);
            s1+=ch1;
        }
        System.out.println(s1);
    }
    void revInt(int n){
        int s=0;
        while(n!=0){
            int r=n%10;
            s=s*10+r;
            n/=10;
        }
        System.out.println(s);
    }
    public static void rev(){
        Scanner sc=new Scanner(System.in);
        Reverse ob=new Reverse();
        while (true){
            System.out.println("1.Reverse of a Word");
            System.out.println("2.Reverse of a No.");
            System.out.println("3.Exit");
            System.out.print("Enter Your option :");
            int ctr=sc.nextInt();
            if(ctr==1){
                System.out.print("Enter a Word:");
                String s=sc.next();
                ob.revStr(s);
            }else if(ctr==2){
                System.out.print("enter a No.:");
                int n=sc.nextInt();
                ob.revInt(n);
            }else if(ctr==3)
                break;
            else{
                System.out.println("Wrong Input");continue;
            }
            System.out.println("");
        }
        sc.close();
    }
}