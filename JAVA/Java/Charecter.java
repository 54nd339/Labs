import java.util.*;
class Charecter{
    static Constant ob=new Constant();
    public static void asc(){
        System.out.println("Char\tASCII\tBinary");
        System.out.println("____\t_____\t______");
        for(int i=1;i<=65536;i++){
            char a=(char)i;
            System.out.print(a+"\t"+i+"\t");
            System.out.println(ob.ToBin(i)+" "+ob.ToHex(i)+"\t"+ob.ToOct(i)+" ");
        }
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        while(true){
            System.out.println("1. To enter a Charecter");
            System.out.println("2. Exit");
            System.out.print("Enter Your option : ");
            int ctr=sc.nextInt();
            if(ctr==1){
                System.out.print("enter a charecter : ");
                char a=sc.next().charAt(0);
                int b=a;
                if(b<=90 && b>=65)
                System.out.println("It is an Upper Class Alphabet");
                else if(b<=122 && b>=97)
                System.out.println("It is a Lower Class Alphabet");
                else if(b<=57 && b>=48)
                System.out.println("It is a Numeric Value");
                else
                System.out.println("It is a Special Charecter");
                System.out.println("The ASCII Value of the Charecter is: "+b);
                System.out.print("The Binary Value of the Charecter is: ");
                System.out.println(ob.ToBin(b)+"");
                System.out.print("The Oct Value of the Charecter is: ");
                System.out.println(ob.ToOct(b)+"");
                System.out.print("The Hex Value of the Charecter is: ");
                System.out.println(ob.ToHex(b)+"");
            }else
            break;
            System.out.println("");
        }
        sc.close();
    }
}