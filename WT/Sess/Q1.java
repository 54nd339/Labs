import java.util.*;
class ModException extends Exception{
    ModException(String s){
        super(s);
    }
}
class Modular{
    int mod;
    Modular(int mod){
        this.mod = mod;
    }
    int reduceMod(int x){
        return x % mod;
    }
    static void check(ModInt a, ModInt b) throws ModException{
        if(a.mod != b.mod)
            throw new ModException("Dissmilar Mods"); 
    }
}
class ModInt extends Modular{
    int n;
    ModInt(int n, int mod){ 
        super(mod);
        this.n = super.reduceMod(n);
    }
    
    ModInt add(ModInt x){
        return new ModInt(this.n + x.n, this.mod);
    }
    ModInt sub(ModInt x){
        return new ModInt(this.n - x.n, this.mod);
    }
    ModInt mul(ModInt x){
        return new ModInt(this.n * x.n, this.mod);
    }
    int display(){
        return this.n;
    }
}

public class Q1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Mod1 and no.1 : ");
        int mod1 = sc.nextInt();
        int n1 = sc.nextInt();
        ModInt a = new ModInt(n1, mod1);

        System.out.println("Enter Mod2 and no.2 : ");
        int mod2 = sc.nextInt();
        int n2 = sc.nextInt();
        ModInt b = new ModInt(n2, mod2);

        try{
            Modular.check(a, b);
            ModInt sum = a.add(b);
            System.out.println(a.display()+" + "+b.display()+" = "+sum.display());
            ModInt dif = a.sub(b);
            System.out.println(a.display()+" - "+b.display()+" = "+dif.display());
            ModInt pro = a.mul(b);
            System.out.println(a.display()+" * "+b.display()+" = "+pro.display());
        }
        catch(ModException e){
            System.out.println(e.getMessage());
        }
    }
}