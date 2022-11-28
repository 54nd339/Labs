import java.util.*;
class Convert{
    int dec2Bin(int n){
        int s=0,c=0;
        while(n!=0){
            int r=n%2;
            s=s+r*(int)Math.pow(10,c);c++;
            n/=2;
        }
        return s;
    }
    String dec2Bin1024(int n){
        String s="";
        while(n!=0){
            int r=n%2;
            s=r+s;
            n/=2;
        }
        return s;
    }
    int dec2Oct(int n){
        int s=0,c=0;
        while(n!=0){
            int r=n%8;
            s=s+r*(int)Math.pow(10,c);c++;
            n/=8;
        }
        return s;
    }
    String dec2Hex(int n){
        String s="";
        while(n!=0){
            int r=n%16;
            if(r>9)
            s=(char)(r+55)+s;
            else
            s=r+s;
            n/=16;
        }
        return s;
    }
    int bin2Dec(int n){
        int s=0,c=0;
        while(n!=0){
            int r=n%10;
            s=s+r*(int)Math.pow(2,c);c++;
            n/=10;
        }
        return s;
    }
    int oct2Dec(int n){
        int s=0,c=0;
        while(n!=0){
            int r=n%10;
            s=s+r*(int)Math.pow(8,c);c++;
            n/=10;
        }
        return s;
    }
    int hex2Dec(String n){
        int s=0,c=0;
        for(int i=n.length()-1;i>=0;i--,c++){
            char ch=n.charAt(i);
            if((int)ch<58 && (int)ch>47)
            s=s+((int)ch-48)*(int)Math.pow(16,c);
            else
            s=s+((int)ch-55)*(int)Math.pow(16,c);
        }
        return s;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        Convert ob=new Convert();
        System.out.println("Conversion Menu");
        System.out.println("1. For Converting Dec to Bin");
        System.out.println("2. For Converting Dec to Oct");
        System.out.println("3. For Converting Dec to Hex");
        System.out.println("4. For Converting Bin to Dec");
        System.out.println("5. For Converting Bin to Oct");
        System.out.println("6. For Converting Bin to Hex");
        System.out.println("7. For Converting Oct to Dec");
        System.out.println("8. For Converting Oct to Bin");
        System.out.println("9. For Converting Oct to Hex");
        System.out.println("10. For Converting Hex to Dec");
        System.out.println("11. For Converting Hex to Bin");
        System.out.println("12. For Converting Hex to Oct");
        System.out.print("Enter Your Choice : ");
        int ch=sc.nextInt(),n=0;String s="";
        if(ch<10){
            System.out.print("Enter The No.:");
            n=sc.nextInt();
        }
        else{
            System.out.print("Enter The String:");
            s=sc.next().toUpperCase();
        }
        if(ch==1) System.out.println(ob.dec2Bin(n));
        else if(ch==2) System.out.println(ob.dec2Oct(n));
        else if(ch==3) System.out.println(ob.dec2Hex(n));
        else if(ch==4) System.out.println(ob.bin2Dec(n));
        else if(ch==5) System.out.println(ob.dec2Oct(ob.bin2Dec(n)));
        else if(ch==6) System.out.println(ob.dec2Hex(ob.bin2Dec(n)));
        else if(ch==7) System.out.println(ob.oct2Dec(n));
        else if(ch==8) System.out.println(ob.dec2Bin(ob.oct2Dec(n)));
        else if(ch==9) System.out.println(ob.dec2Hex(ob.oct2Dec(n)));
        else if(ch==10) System.out.println(ob.hex2Dec(s));
        else if(ch==11) System.out.println(ob.dec2Bin(ob.hex2Dec(s)));
        else if(ch==12) System.out.println(ob.dec2Oct(ob.hex2Dec(s)));
        else System.out.println("Wrong Input");
        sc.close();
    }
}