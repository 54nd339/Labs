class SuperClass{
    public void display(){
        System.out.println("SuperClass");
    }
}
interface Interface1{
    static void display(){
        System.out.println("Static Interface");
    }
}
interface Interface2{
    default void display(){
        System.out.println("Default Interface");
    }
}
public class Class extends SuperClass implements Interface1, Interface2 {
    void idisplay(){
        Interface2.super.display();
    }
    public static void main(String[] args) {
        Class ob = new Class();
        ob.display();
        Interface1.display();
        ob.idisplay();
    }
}