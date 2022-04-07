class CheckArgumentException extends Exception{
    CheckArgumentException(String s){
        super(s);
    }
}

public class Q6{
    public static void main(String args[]) throws CheckArgumentException{
        try{
            if(args.length < 4)
                throw new CheckArgumentException("CheckArgumentException Handled");
            else {
                int sum = 0;
                for (int i = 0; i < args.length; i++){
                    int x = Integer.parseInt(args[i]);
                    sum += x*x;
                }
                System.out.println("Sum : " + sum);
            }
        }
        catch(Exception m){
            System.out.println(m.getMessage());
        }
    }
}