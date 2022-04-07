class Parent{
    void msg() throws Exception{
        System.out.println("parent");
    }
}
    
class Q2 extends Parent{
    void msg() throws ArithmeticException{
        System.out.println("child");
    }
    public static void main(String args[]){
        Parent p = new Q2();
        try{
            p.msg();
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}