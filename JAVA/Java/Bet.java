import java.util.*;
class Bet{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n;
        while(true){
            System.out.print("Enter The no. of players : ");
            n=sc.nextInt();
            System.out.print("Sure? Enter \"Y\" for \"Yes\" or \"N\" for \"No\":");
            String C=sc.next();
            if(C.equalsIgnoreCase("Y"))
            break;
            else if(C.equalsIgnoreCase("N"));
            else System.out.println("Wrong Input! Try Again..");
        }

        String ar[]=new String[n];
        int bal[]=new int[n];
        for(int a=1;a<=n;a++){
            String na="";
            while(true){
                System.out.print("Enter The name of player "+a+" : ");
                na=sc.next();
                System.out.print("Sure? Enter \"Y\" for \"Yes\" or \"N\" for \"No\" : ");
                String C=sc.next();
                if(C.equalsIgnoreCase("Y"))
                break;
                else if(C.equalsIgnoreCase("N"));
                else System.out.println("Wrong Input! Try Again..");
            }
            ar[a-1]=na;bal[a-1]=10000;
        }
        System.out.println();
        
        int ro=1,j=0,bet=0;
        while(true){
            System.out.println();
            System.out.println("Round "+ro);
            for(int i=0;i<ar.length;i++){
                System.out.println(ar[i]+"'s Chance : ");
                do{
                  System.out.print("Enter a no. between 0-9 : ");
                  j=sc.nextInt();
                  if(j>=10)
                  System.out.println("Wrong Input! Try Again..");
                }while(j>=10);
                do{
                  System.out.print("Enter Your Bet Amount(More Than 1000) : ");
                  bet=sc.nextInt();
                  if(bet<=1000)
                  System.out.println("Wrong Input! Try Again..");
                }while(bet<=1000);
                int r=(int)(Math.random()*10);
                if(j==r){
                    System.out.println("Congrats!Your balance increased.");
                    bal[i]+=bet;
                }
                else{
                    System.out.println("Sorry! The No. is "+r);
                    bal[i]-=bet;
                }
                System.out.println();
            }
            for(int i=0;i<ar.length;i++)
            System.out.println(ar[i]+"'s balance is "+bal[i]);
            int z=0;
            outer:
            while(true){
                System.out.print("Exit? Enter \"Y\" for \"Yes\" or \"N\" for \"No\" : ");
                String m=sc.next();
                if(m.equalsIgnoreCase("Y")){
                    System.out.print("Sure? Enter \"Y\" for \"Yes\" or \"N\" for \"No\" : ");
                    String C=sc.next();
                    if(C.equalsIgnoreCase("Y")){
                        z=1;break outer;
                    }
                }
                else if(m.equalsIgnoreCase("N"))
                break;
                else 
                System.out.println("Wrong Input! Try Again..");
            }
            if(z==1)
            break;
            ro+=1;
        }

        sc.close();
    }
}