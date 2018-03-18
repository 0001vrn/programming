/*
2.1 Write code to remove duplicates from an unsorted linked list.
    FOLLOW UP
    How would you solve this problem if a temporary buffer is not allowed?

by    : Varun Thakur
dated : 18-03-2018
*/
import java.util.Hashtable;

class LinkedList{
    
    Node head;  // head of list
 
    /* Linked list Node.  This inner class is made static so that
       main() can access it */
    static class Node {
        int data;
        Node next;
        Node(int d)  { data = d;  next=null; } // Constructor
    }
    
    /* This function prints contents of linked list starting from head */
    public void printList()
    {
        Node n = head;
        while (n != null)
        {
            System.out.print(n.data+"->");
            n = n.next;
        }
        System.out.println("NULL");
    }
    public static void deleteDups(Node n) {
        Hashtable table = new Hashtable();
        Node previous = null;
        while (n != null) {
            if (table.containsKey(n.data)) 
                previous.next = n.next;
            else {
                table.put(n.data, true);
                previous = n;
            }
            n = n.next;
            }
        }
    public static void main(String[] args){
        /* Start with the empty list. */
        LinkedList llist = new LinkedList();
 
        llist.head  = new Node(1);
        Node second = new Node(1);
        Node third  = new Node(3);
 
        llist.head.next = second; // Link first node with the second node
 
        second.next = third; // Link second node with the third node
        
        llist.printList();
        deleteDups(llist.head);
        llist.printList();

    }
}