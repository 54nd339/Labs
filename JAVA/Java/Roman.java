import java.util.*;
class Roman{
    static Roman ob=new Roman();
    String toRom(int n){
        String m[]={"","M","MM","MMM"};
        String c[]={"","C","CC","CCC","CD","D",
                    "DC","DCC","DCCC","CM"};
        String x[]={"","X","XX","XXX","XL","L",
                    "LX","LXX","LXXX","XC"};
        String i[]={"","I","II","III","IV","V",
                    "VI","VII","VIII","IX"};
        String tho=m[n/1000];
        String hun=c[(n%1000)/100];
        String ten=x[(n%100)/10];
        String one=i[n%10];
        return tho+hun+ten+one;
    }
    public static void series(){
        for(int i=1;i<4000;i++)
        System.out.println(i+"\t"+ob.toRom(i));
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a No. below 4000 : ");
        int n=sc.nextInt();
        if(n<4000)
        System.out.println(n+":\t"+ob.toRom(n));
        else
        System.out.println("Wrong Input");
        sc.close();
    }
}