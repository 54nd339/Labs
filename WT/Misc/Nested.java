public class Nested{
    public static void main(String[] args){
        int ar[] = new int[]{2, 3, 4};
        try{
            try{
                System.out.println("ar[3] : "+ar[3]);
            }
            catch(Exception e){
                System.out.println(e.getMessage());
            }
            finally{
                System.out.println("Inside Try");
                System.out.println(ar.length/0);
            }
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
        finally{
            System.out.println("Main");
        }
    }
}