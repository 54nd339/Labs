public class Q3 {
	public static void main (String[] args) {
        int arr[] = {1, 2, 3, 4};
        try {
            System.out.println( arr[4]);
		}
        catch(Exception ex) {
			System.out.println("Exception has been caught");
		}
		/*catch(NullPointerException ex) {
			System.out.println("Exception has been caught");
		}*/
		finally {
			System.out.println("finally block executed");
		}
        System.out.println("Outside try-catch-finally clause");
	}
}