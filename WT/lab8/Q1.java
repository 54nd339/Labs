public class Q1 {
    public static void main(String[] args) {
        int arr[] = {2,7,9};
        try{
            System.out.println("Ar[2] : " + arr[2]);
            System.out.println("Ar[3] : " + arr[3]);
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}