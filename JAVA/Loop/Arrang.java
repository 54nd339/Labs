import java.util.*;
class Arrang{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        Reverse ob=new Reverse();
        while (true){
            System.out.println("1.Arrange a Number");
            System.out.println("2.Arrange a Word");
            System.out.println("3.Exit");
            System.out.print("Enter your option : ");
            int ctr=sc.nextInt(),ctr1=0;
            if(ctr==1 || ctr==2){
                System.out.println("1.Ascending");
                System.out.println("2.Descending");
                System.out.print("Enter your option : ");
                ctr1=sc.nextInt();}
            if(ctr==1){
                System.out.print("Enter a No. : ");
                int n=sc.nextInt(),m=0;
                for(int i=0;i<10;i++){
                    int p=n;
                    while(p!=0){
                        int r=p%10;
                        if(r==i)
                            m=m*10+r;
                        p=p/10;
                    }
                }
                if(ctr1==1)
                    System.out.println(m);
                else
                    ob.revInt(m);
            }else if(ctr==2){
                System.out.print("Enter a Word : ");
                String s=sc.next(),s1="";
                for(int i=65;i<=90;i++){
                    for(int j=0;j<s.length();j++){
                        char ch=s.charAt(j);
                        if(ch==(char)i||ch==(char)(i+32))
                            s1+=ch;
                    }
                }
                if(ctr1==1)
                    System.out.println(s1);
                else
                    ob.revStr(s1);
            }else if (ctr==3)
                break;
            else{
                System.out.println("Wrong Input");continue;
            }
            System.out.println();
        }
        sc.close();
    }
}