class Base{
    void display(){
        System.out.println("From Base");
    }
}
class Derived extends Base{
    void show(){
        System.out.println("From Derived");
        super.display();
    }
}
public class Q13{
    public static void main(String[] args){
        Derived ob = new Derived();
        ob.show();
    }
}