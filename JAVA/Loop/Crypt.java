import java.util.*;
class Crypt{
    static Scanner sc=new Scanner(System.in);
    static Crypt ob1=new Crypt();
    static Convert ob=new Convert();
    String RotE(String s){
        System.out.print("Enter the Shift:");
        int n=sc.nextInt(),a,z;String s1="";
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            int b=(int)ch+n;
            if(Character.isLetter(ch)){
                if(Character.isUpperCase(ch))
                {a=65;z=90;}
                else
                {a=97;z=122;}
                while(b<a)
                b+=26;
                while(b>z)
                b-=26;
                s1+=(char)b;
            }
            /*else if(ch==' ')
            for(int j=1;j<=2;j++)
            s1+=(char)((int)'Q'+n);*/
            else
            s1=s1+ch;
        }
        return s1;
    }
    String RotD(String s){
        System.out.print("Enter the shift:");
        int n=sc.nextInt(),a,z;String s1="";
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            int b=(int)ch-n;
            if(Character.isLetter(ch)){
                if(Character.isUpperCase(ch))
                {a=65;z=90;}
                else 
                {a=97;z=122;}
                while(b<a)
                b+=26;
                while(b>z)
                b-=26;
                if(b==(int)'Q' && (int)s.charAt(i+1)-n==(int)'Q' && i<s.length()){
                b=32;i++;}
                s1+=(char)b;
            }
            else
            s1=s1+ch;
        }
        return s1;
    }
    String B64E(String S){
        String chs="",bin="",fb="";int count=0;
        for(int i=0;i<S.length();i++){
            bin=ob.dec2Bin1024((int)(S.charAt(i)));
            while(bin.length()<8){
                bin=0+bin;
            }
            fb+=bin;
            //System.out.println("bin:"+bin+" fb:"+fb);
        }
        while(fb.length()%6!=0){
            fb+="00";count++;
        }
        for(int i=0;i<fb.length();i+=6){
            chs+=ob1.hash(ob.bin2Dec(Integer.parseInt(fb.substring(i,i+6))),"");
        }
        //System.out.println(chs);
        if(count==1)
            return chs+"=";
        else
            return chs+"==";
    }
    String B64D(String chs){
        String bin="",fS="",S="";
        for(int i=0;i<chs.length();i++){
            char ch=chs.charAt(i);
            if(ch!='='){
                bin=ob.dec2Bin1024(Integer.parseInt(ob1.hash(64,""+ch)));
                while(bin.length()<6){
                    bin=0+bin;
                }
            }
            else{
                fS=fS.substring(0,fS.length()-2);bin="";
            }
            fS+=bin;
            //System.out.println("bin:"+bin+" fS:"+fS);
        }
        for(int i=0;i<fS.length();i+=8){
            S+=(char)ob.bin2Dec(Integer.parseInt(fS.substring(i,i+8)));
        }
        return S;
    }
    public static void mainE1(){
        System.out.print("Enter a String:");
        String S=sc.nextLine();
        System.out.print(ob1.B64E(ob1.RotE(S)));
    }
    public static void mainD1(){
        System.out.print("Enter a String:");
        String S=sc.nextLine();
        System.out.print(ob1.RotD(ob1.B64D(S)));
    }
    public static void mainE2(){
        System.out.print("Enter a String:");
        String S=sc.nextLine();
        System.out.print(ob1.RotE(ob1.B64E(S)));
    }
    public static void mainD2(){
        System.out.print("Enter a String:");
        String S=sc.nextLine();
        System.out.print(ob1.B64D(ob1.RotD(S)));
    }
    String hash(int n, String S){
        if (n==0) return "A";
        else if (n==1) return "B";
        else if (n==2) return "C";
        else if (n==3) return "D";
        else if (n==4) return "E";
        else if (n==5) return "F";
        else if (n==6) return "G";
        else if (n==7) return "H";
        else if (n==8) return "I";
        else if (n==9) return "J";
        else if (n==10) return "K";
        else if (n==11) return "L";
        else if (n==12) return "M";
        else if (n==13) return "N";
        else if (n==14) return "O";
        else if (n==15) return "P";
        else if (n==16) return "Q";
        else if (n==17) return "R";
        else if (n==18) return "S";
        else if (n==19) return "T";
        else if (n==20) return "U";
        else if (n==21) return "V";
        else if (n==22) return "W";
        else if (n==23) return "X";
        else if (n==24) return "Y";
        else if (n==25) return "Z";
        else if (n==26) return "a";
        else if (n==27) return "b";
        else if (n==28) return "c";
        else if (n==29) return "d";
        else if (n==30) return "e";
        else if (n==31) return "f";
        else if (n==32) return "g";
        else if (n==33) return "h";
        else if (n==34) return "i";
        else if (n==35) return "j";
        else if (n==36) return "k";
        else if (n==37) return "l";
        else if (n==38) return "m";
        else if (n==39) return "n";
        else if (n==40) return "o";
        else if (n==41) return "p";
        else if (n==42) return "q";
        else if (n==43) return "r";
        else if (n==44) return "s";
        else if (n==45) return "t";
        else if (n==46) return "u";
        else if (n==47) return "v";
        else if (n==48) return "w";
        else if (n==49) return "x";
        else if (n==50) return "y";
        else if (n==51) return "z";
        else if (n==52) return "0";
        else if (n==53) return "1";
        else if (n==54) return "2";
        else if (n==55) return "3";
        else if (n==56) return "4";
        else if (n==57) return "5";
        else if (n==58) return "6";
        else if (n==59) return "7";
        else if (n==60) return "8";
        else if (n==61) return "9";
        else if (n==62) return "+";
        else if (n==63) return "/";
        else if (S.equals("A")) return "0";
        else if (S.equals("B")) return "1";
        else if (S.equals("C")) return "2";
        else if (S.equals("D")) return "3";
        else if (S.equals("E")) return "4";
        else if (S.equals("F")) return "5";
        else if (S.equals("G")) return "6";
        else if (S.equals("H")) return "7";
        else if (S.equals("I")) return "8";
        else if (S.equals("J")) return "9";
        else if (S.equals("K")) return "10";
        else if (S.equals("L")) return "11";
        else if (S.equals("M")) return "12";
        else if (S.equals("N")) return "13";
        else if (S.equals("O")) return "14";
        else if (S.equals("P")) return "15";
        else if (S.equals("Q")) return "16";
        else if (S.equals("R")) return "17";
        else if (S.equals("S")) return "18";
        else if (S.equals("T")) return "19";
        else if (S.equals("U")) return "20";
        else if (S.equals("V")) return "21";
        else if (S.equals("W")) return "22";
        else if (S.equals("X")) return "23";
        else if (S.equals("Y")) return "24";
        else if (S.equals("Z")) return "25";
        else if (S.equals("a")) return "26";
        else if (S.equals("b")) return "27";
        else if (S.equals("c")) return "28";
        else if (S.equals("d")) return "29";
        else if (S.equals("e")) return "30";
        else if (S.equals("f")) return "31";
        else if (S.equals("g")) return "32";
        else if (S.equals("h")) return "33";
        else if (S.equals("i")) return "34";
        else if (S.equals("j")) return "35";
        else if (S.equals("k")) return "36";
        else if (S.equals("l")) return "37";
        else if (S.equals("m")) return "38";
        else if (S.equals("n")) return "39";
        else if (S.equals("o")) return "40";
        else if (S.equals("p")) return "41";
        else if (S.equals("q")) return "42";
        else if (S.equals("r")) return "43";
        else if (S.equals("s")) return "44";
        else if (S.equals("t")) return "45";
        else if (S.equals("u")) return "46";
        else if (S.equals("v")) return "47";
        else if (S.equals("w")) return "48";
        else if (S.equals("x")) return "49";
        else if (S.equals("y")) return "50";
        else if (S.equals("z")) return "51";
        else if (S.equals("0")) return "52";
        else if (S.equals("1")) return "53";
        else if (S.equals("2")) return "54";
        else if (S.equals("3")) return "55";
        else if (S.equals("4")) return "56";
        else if (S.equals("5")) return "57";
        else if (S.equals("6")) return "58";
        else if (S.equals("7")) return "59";
        else if (S.equals("8")) return "60";
        else if (S.equals("9")) return "61";
        else if (S.equals("+")) return "62";
        else if (S.equals("/")) return "63";
        else return "";
    }
}