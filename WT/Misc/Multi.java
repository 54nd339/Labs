interface Int1{
    void display();
}
interface Int2 extends Int1{
    void show();
}
class Super{
    Super(){
        System.out.println("Super");
    }
}
class Child extends Super implements Int2{
    Child(){
        System.out.println("Child");
    }
    public void show(){
        System.out.println("Int2");
    }
    public void display(){
        System.out.println("Int1");
    }
}
public class Multi{
    public static void main(String args[]){
        Child ob = new Child();
        ob.show();
        ob.display();
    }
}