import java.util.*;
class Ser{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the last no. : ");
        int i=sc.nextInt();
        for(int n=2;n<=i;n++){
            System.out.println("--------------------------");
            System.out.println("           "+n);
            System.out.println("--------------------------");
            System.out.println("                  Yes   No");
            System.out.println("                  ---   --");
            Is ob=new Is();
            if(ob.isArm(n))
                System.out.println("Armstrong no.  :   X");
            else
                System.out.println("Armstrong no.  :         X");
            if(ob.isAuto(n))
                System.out.println("Automorphic no.:   X");
            else
                System.out.println("Automorphic no.:         X");
            if(ob.isBou(n))
                System.out.println("Bouncy no.     :   X");
            else
                System.out.println("Bouncy no.     :         X");
            if(ob.isBuzz(n))
                System.out.println("Buzz no.       :   X");
            else
                System.out.println("Buzz no.       :         X");
            if(ob.isDis(n))
                System.out.println("Disarium no.   :   X");
            else
                System.out.println("Disarium no.   :         X");
            if(ob.isDuc(n))
                System.out.println("Duck no.       :   X");
            else
                System.out.println("Duck no.       :         X");
            if(ob.isEvil(n))
                System.out.println("Evil no.       :   X");
            else
                System.out.println("Evil no.       :         X");
            if(ob.isFasc(n))
                System.out.println("Fascinate no.  :   X");
            else
                System.out.println("Fascinate no.  :         X");
            if(ob.isHap(n))
                System.out.println("Happy no.      :   X");
            else
                System.out.println("Happy no.      :         X");
            if(ob.isKap(n))
                System.out.println("Kaprekar no.   :   X");
            else
                System.out.println("Kaprekar no.   :         X");
            if(ob.isMagi(n))
                System.out.println("Magic no.      :   X");
            else
                System.out.println("Magic no.      :         X");
            if(ob.isNeo(n))
                System.out.println("Neon no.       :   X");
            else
                System.out.println("Neon no.       :         X");
            if(ob.isNiv(n))
                System.out.println("Niven no.      :   X");
            else
                System.out.println("Niven no.      :         X");
            if(ob.isPalin(n))
                System.out.println("Palindrome no. :   X");
            else
                System.out.println("Palindrome no. :         X");
            if(ob.isPer(n))
                System.out.println("Perfect no.    :   X");
            else
                System.out.println("Perfect no.    :         X");
            if(ob.isPP(n))
                System.out.println("Prime Perfect n:   X");
            else
                System.out.println("Prime Perfect n:         X");
            if(ob.isPron(n))
                System.out.println("Pronic no.     :   X");
            else
                System.out.println("Pronic no.     :         X");
            if(ob.isRect(n))
                System.out.println("Rectangular no.:   X");
            else
                System.out.println("Rectangular no.:         X");
            if(ob.isSmit(n))
                System.out.println("Smith no.      :   X");
            else
                System.out.println("Smith no.      :         X");
            if(ob.isSpec(n))
                System.out.println("Special no.    :   X");
            else
                System.out.println("Special no.    :         X");
            if(ob.isSp2(n))
                System.out.println("Sum Product no.:   X");
            else
                System.out.println("Sum Product no.:         X");
            if(ob.isSP(n))
                System.out.println("Special 2D no. :   X");
            else
                System.out.println("Special 2D no. :         X");
            if(ob.isSp(n))
                System.out.println("Sphenic no.    :   X");
            else
                System.out.println("Sphenic no.    :         X");
            if(ob.isSp(n))
                System.out.println("Sphenic no.    :   X");
            else
                System.out.println("Sphenic no.    :         X");
            if(ob.isTri(n))
                System.out.println("Triangular no. :   X");
            else
                System.out.println("Triangular no. :         X");
            if(ob.isUniq(n))
                System.out.println("Unique no.     :   X");
            else
                System.out.println("Unique no.     :         X");
            if(ob.isPrime(n)){
                System.out.println("Prime no.      :   X");
                if(ob.isTP(n))
                System.out.println("Twisted Prime n:   X");
                else
                System.out.println("Twisted Prime n:         X");
                if(ob.isCP(n))
                System.out.println("Circular Prime :   X");
                else
                System.out.println("Circular Prime :         X");
            }
            else
                System.out.println("Prime no.      :         X");
            System.out.println();
            System.out.println("Factorial of "+n+" is "+ob.fact(n));
            ob.pf(n);
            System.out.println("Mobius Value of "+n+" is "+ob.mobVal(n));
            System.out.println();
            System.out.println();
        }
        sc.close();
    }
}