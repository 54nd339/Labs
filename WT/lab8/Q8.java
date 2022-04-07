import java.util.Scanner;
class Input{
    static Scanner sc = new Scanner(System.in);
}
class OverflowException extends Exception{
    OverflowException(String s){
        super(s);
    }
}
class UnderflowException extends Exception{
    UnderflowException(String s){
        super(s);
    }
}
class Stack {
	static int cap;
	int top, a[];

	Stack() {
        System.out.print("Enter Size of Stack : ");
        cap = Input.sc.nextInt(); top = -1;
        a = new int[cap];
	}

	void push() throws OverflowException {
        System.out.print("Enter No. to be pushed : ");
        int x = Input.sc.nextInt();
		if (top >= (cap-1)) 
            throw new OverflowException("Stack is full");
		else {
			a[++top] = x;
			System.out.println(x + " pushed into stack");
		}
	}

	int pop() throws UnderflowException {
		if (top < 0) 
            throw new UnderflowException("Stack is empty");
		else {
			int x = a[top--];
			return x;
		}
	}
    int peek() throws UnderflowException {
        if (top < 0) 
            throw new UnderflowException("Stack is empty");
		else
            return a[top];
    }
    void print() throws UnderflowException {
        if (top < 0) 
            throw new UnderflowException("Stack is empty");
		else {
            for(int i=top; i>-1; i--)
            System.out.print(" "+ a[i]);
        }
    }
}

public class Q8 {
	public static void main(String args[]) {
		Stack ob = new Stack();
        System.out.println("1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit");
        while(true){
            System.out.print("\nEnter your choice : ");
            int ch = Input.sc.nextInt();
            if(ch == 1) {
                try{
                    ob.push();
                }
                catch(Exception e){
                    System.out.println(e.getMessage());
                }
            }
            else if(ch == 2) {
                try{
                    System.out.println("Popped Element : "+ob.pop());
                }
                catch(Exception e){
                    System.out.println(e.getMessage());
                }
            }
            else if(ch == 3) {
                try {
                    System.out.println("Top Element : "+ob.peek());
                }
                catch(Exception e){
                    System.out.println(e.getMessage());
                }
            }
            else if(ch == 4) {
                try {
                    ob.print();
                }
                catch(Exception e){
                    System.out.println(e.getMessage());
                }
            }
            else if(ch == 0) break;
            else System.out.println("Wrong choice.");
        }
	}
}