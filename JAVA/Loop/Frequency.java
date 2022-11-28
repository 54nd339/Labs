import java.util.*;
class Frequency{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        while (true){
            System.out.println("1.Frequency of a Number");
            System.out.println("2.Frequency of a Charecter");
            System.out.println("3.Exit");
            System.out.print("Enter your option : ");
            int ctr=sc.nextInt();
            if(ctr==1){
                System.out.print("Enter a No. : ");
                int n=sc.nextInt();
                for(int i=0;i<10;i++){
                    int p=n,q=0;
                    while(p!=0){
                        int r=p%10;
                        if(r==i){
                            q++;
                        }p/=10;
                    }
                    if(q==0);
                    else
                        System.out.println("The Frequency of "+i+" is "+q);
                }
            }else if(ctr==2){
                System.out.print("Enter a Word : ");
                String a=sc.next().toLowerCase();
                int b=a.length();char e='a';
                for(char c='a';c<='z';c++){
                    int q=0;
                    for(int d=0;d<b;d++){
                        e=a.charAt(d);
                        if(e==c||e==c+32)
                            q++;
                    }
                    if(q==0);
                    else{
                        System.out.println("The Frequency of "+c+" is "+q);
                    }
                }
            }else if (ctr==3)
                break;
            else
                System.out.println("Wrong Input.");
            System.out.println();
        }
        sc.close();
    }
}