import java.util.*;
class Num{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a no. : ");
        int n=sc.nextInt();
        Is ob= new Is();
        if(ob.isArm(n))
            System.out.println(n+" is a Armstrong no.");
        if(ob.isAuto(n))
            System.out.println(n+" is a Automorphic no.");
        if(ob.isBou(n))
            System.out.println(n+" is a Bouncy no.");
        if(ob.isBuzz(n))
            System.out.println(n+" is a Buzz no.");
        if(ob.isDis(n))
            System.out.println(n+" is a Disarium no.");
        if(ob.isDuc(n))
            System.out.println(n+" is a Duck no.");
        if(ob.isEvil(n))
            System.out.println(n+" is a Evil no.");
        if(ob.isFasc(n))
            System.out.println(n+" is a Fascinate no.");
        if(ob.isHap(n))
            System.out.println(n+" is a Happy no.");
        if(ob.isKap(n))
            System.out.println(n+" is a Kaprekar no.");
        if(ob.isMagi(n))
            System.out.println(n+" is a Magic no.");
        if(ob.isNeo(n))
            System.out.println(n+" is a Neon no.");
        if(ob.isNiv(n))
            System.out.println(n+" is a Niven no.");
        if(ob.isPalin(n))
            System.out.println(n+" is a Palindrome no.");
        if(ob.isPer(n))
            System.out.println(n+" is a Perfect no.");
        if(ob.isPP(n))
            System.out.println(n+" is a Prime Perfect no.");
        if(ob.isPron(n))
            System.out.println(n+" is a Pronic no.");
        if(ob.isRect(n))
            System.out.println(n+" is a Rectangular no.");
        if(ob.isSmit(n))
            System.out.println(n+" is a Smith no.");
        if(ob.isSpec(n))
            System.out.println(n+" is a Special no.");
        if(ob.isSp2(n))
            System.out.println(n+" is a Special 2D no.");
        if(ob.isSP(n))
            System.out.println(n+" is a Sum Product no.");
        if(ob.isSp(n))
            System.out.println(n+" is a Sphenic no.");
        if(ob.isTri(n))
            System.out.println(n+" is a Triangular no.");
        if(ob.isUniq(n))
            System.out.println(n+" is a Unique no.");
        if(ob.isPrime(n)){
            System.out.println(n+" is a Prime no.");
            if(ob.isTP(n))
                System.out.println(n+" is a Twisted Prime no.");
            if(ob.isCP(n))
                System.out.println(n+" is a Circular Prime no.");
        }
        System.out.println("Factorial of "+n+" is "+ob.fact(n));
        ob.pf(n);
        System.out.println("Mobius Value of "+n+" is "+ob.mobVal(n));
        ob.gold(n);
        sc.close();
    }
}