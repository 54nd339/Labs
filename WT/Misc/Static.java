class Test{
    static int a;
    Test(){
        a++;
    }
    static {
        a = 0;
        System.out.println("Static initialised");
    }
}
public class Static {
    public static void main(String[] args) {
        Test ob1 = new Test();
        Test ob2 = new Test();
        Test ob3 = new Test();
        System.out.println("No. of instances created : "+Test.a);
    }
}