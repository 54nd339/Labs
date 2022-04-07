import java.util.Scanner;
class MyVolume{
    float l, b, h; double r;
    MyVolume(float length, float breadth, float height){
        l = length; b = breadth; h = height;
    }
    MyVolume(float length){
        l = b = h = length;
    }
    MyVolume(double radius){
        r = radius;
    }
    void calc(float length, float breadth, float height){
        System.out.println("Volume : "+ (length*breadth*height));
    }
    void calc(double r){
        System.out.println("Volume : "+ ((4/3)*3.14*r*r*r));
    }
}
public class Q8{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter dimensions of cuboid : ");
        float length = sc.nextFloat();
        float breadth = sc.nextFloat();
        float height = sc.nextFloat();
        MyVolume cuboid = new MyVolume(length, breadth, height);
        cuboid.calc(cuboid.l, cuboid.b, cuboid.h);

        System.out.print("\nEnter length of cube : ");
        float len = sc.nextFloat();
        MyVolume cube = new MyVolume(len);
        cuboid.calc(cube.l, cube.b, cube.h);

        System.out.print("\nEnter radius of sphere : ");
        double radius = sc.nextDouble();
        MyVolume sphere = new MyVolume(radius);
        cuboid.calc(sphere.r);
    }
}