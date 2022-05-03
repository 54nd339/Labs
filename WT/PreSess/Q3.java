import java.util.*;
class LL {
    Node head;
    static class Node {
        int data;
        Node next;
        Node(int d) { data = d; }
    }
    static LL insert(LL list, int data) {
        Node new_node = new Node(data);
        new_node.next = null;
        if (list.head == null) 
            list.head = new_node;
        else {
            Node last = list.head;
            while (last.next != null) 
                last = last.next;
            last.next = new_node;
        }
        return list;
    }
    static void printList(LL list) {
        Node temp = list.head;
        System.out.print("Linked List : ");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
    static int search(LL list, int key) {
        Node currNode = list.head, prev = null; int j = 0;
        if (currNode != null && currNode.data == key)
            return j;
        while (currNode != null && currNode.data != key) {
            currNode = currNode.next; j++;
        }
        return (currNode != null) ? j : -1;
    }
    static LL delAtPos(LL list, int index) {
        Node currNode = list.head, prev = null;
        if (index == 0 && currNode != null) {
            list.head = currNode.next;
            System.out.println(index + " position element deleted");
            return list;
        }
        int counter = 0;
        while (currNode != null) {
            if (counter == index) {
                prev.next = currNode.next;
                System.out.println(index + " position element deleted");
                break;
            }
            else {
                prev = currNode;
                currNode = currNode.next;
                counter++;
            }
        }
        if (currNode == null) 
            System.out.println(index + " position element not found");
        return list;
    }
}
public class Q3 {
    public static void main(String[] args) {
        LL list = new LL();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter elements (-1 to exit) : ");
        while(true){
            int n = sc.nextInt();
            if(n == -1)
                break;
            list = LL.insert(list, n);
        }
        LL.printList(list);
        
        System.out.print("\nEnter element to be searched : ");
        int key = sc.nextInt();
        System.out.println(key + " found at position " + LL.search(list, key));

       
        System.out.print("Enter position to be deleted : ");
        int pos = sc.nextInt();
        LL.printList(LL.delAtPos(list, pos));

        System.out.print("\nEnter element to be deleted : ");
        key = sc.nextInt();
        LL.printList(LL.delAtPos(list, LL.search(list, key)));
    }
}