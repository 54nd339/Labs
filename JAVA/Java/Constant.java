class Constant{
    String ToBin(int n){
        String s="";
        while(n!=0){
            int r=n%2;
            s=r+s;
            n/=2;
        }
        return s;
    }
    int ToOct(int n){
        int s=0,c=0;
        while(n!=0){
            int r=n%8;
            s=s+r*(int)Math.pow(10,c);c++;
            n/=8;
        }
        return s;
    }
    String ToHex(int n){
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
    public static void main(){
        Constant ob=new Constant();
        System.out.println("Char\tASCII\tBinary\tHex\tOct");
        System.out.println("____\t_____\t______\t___\t___");
        char a;
        for(a='a';a<='z';a++){
            System.out.print(a+"\t"+(int)a+"\t");
            System.out.println(ob.ToBin((int)a)+" "+ob.ToHex((int)a)+"\t"+ob.ToOct((int)a)+" ");
        }
        System.out.println("");
        for(a='A';a<='Z';a++){
            System.out.print(a+"\t"+(int)a+"\t");
            System.out.println(ob.ToBin((int)a)+" "+ob.ToHex((int)a)+"\t"+ob.ToOct((int)a)+" ");
        }
        System.out.println("");
        for(a='0';a<='9';a++){
            System.out.print(a+"\t"+(int)a+"\t");
            System.out.println(ob.ToBin((int)a)+" "+ob.ToHex((int)a)+"\t"+ob.ToOct((int)a)+" ");
        }
    }
}