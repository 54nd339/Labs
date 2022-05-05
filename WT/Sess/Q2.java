import java.util.Scanner;
import java.io.*;
public class Q2 {
    public static void main(String args[]) throws Exception {
        Scanner sc = null;
        FileWriter fw = null;
        try {
            File ob = new File("C:\\Users\\KIIT\\OneDrive\\Documents\\Programming\\Labs\\WT\\Sess\\temp.txt");
            sc = new Scanner(ob);
            String output = "";
            while (sc.hasNext()) {
                String word = sc.nextLine();
                output += word.replace('#','*')+"/";
            }
            fw = new FileWriter("C:\\Users\\KIIT\\OneDrive\\Documents\\Programming\\Labs\\WT\\Sess\\out.txt");
            fw.write(output);
            System.out.println("Done");
        }
        catch (IOException e) {
            System.out.print(e.getMessage());
        }
        finally {
            fw.close();
            sc.close();
        }
    }
}