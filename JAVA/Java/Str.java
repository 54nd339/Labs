import javax.swing.*;
class Str{
    public static void main(String args[]){
        Str ob=new Str();
        System.out.println("Dear mom.. ");
        ob.print("       No matter what I become       ");
        ob.print("   I'll always be your little one    ");
        ob.print(" The child you carried in your arms  ");
        ob.print("With whom you shared memories, so fun");
        ob.print("   Of guessing, exactly how I feel   ");
        ob.print("   You always seem to have a knack   ");
        ob.print("    No matter how much I grow up     ");
        ob.print(" I know you will always watch my back");
        ob.print("             I love you              ");
        ob.print("     My mother,My friend so dear     ");
        ob.print("   Throughout my life you're near    ");
        ob.print("   A tender smile to guide my way    ");
        ob.print(" you're the sunshine to light my way.");
        for(double i=1;i<=500000000;i++);
        ob.pic();
    }
    void print(String S){
        for(double i=1;i<=500000000;i++);
        System.out.println(S);
    }
    void pic(){
        JFrame frame=new JFrame();
        JLabel label=new JLabel(new ImageIcon("IMG_20160912_162421.jpg"));
        frame.add(label);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}