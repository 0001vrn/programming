/*
2.1 Write code to remove duplicates from an unsorted linked list.
    FOLLOW UP
    How would you solve this problem if a temporary buffer is not allowed?
    
2.2 Implement an algorithm to find the nth to last element of a singly linked list.

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
    public static void deleteDups(Node head) {
        Hashtable table = new Hashtable();
        Node previous = null;
        while (head != null) {
            if (table.containsKey(head.data)) 
                previous.next = head.next;
            else {
                table.put(head.data, true);
                previous = head;
            }
        head = head.next;
        }
    }
    /*
    Time Complexity: O(1)
    Space Complexity: O(n)
    */
    public static void deleteDups2(Node head){
        if(head == null)
            return;
        Node previous = head;
        Node current = previous.next;
        while(current!=null){
            Node runner = head;
            while(runner!=current){
                if(runner.data == current.data){
                    Node tmp = current.next;
                    previous.next = tmp;
                    current = tmp;
                    break;
                }
                runner = runner.next;
            }
            
            if (runner == current) { // current not updated - update now
                previous = current;
                current = current.next;
            }
        }
    }
    /*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
    public static int getLen(Node head){
        if(head==null)
            return 0;
        return 1+getLen(head.next);
    }
    /*
    Time Complexity: O(n)
    */
    
    public static Node nthToLast(Node head, int n){
        if(head == null || n < 1)
            return null;
        Node p1 = head;
        Node p2 = head;
        for(int i=0;i<n-1;i++){
            if(p2.next == null)
                return null;
            p2 = p2.next;
        }
        while(p2.next!=null){
            p1 = p1.next;
            p2 = p2.next;
        }
        
        return p1;
    }
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    
    public static Node nthToLast2(Node head, int n){
        if(head == null || n < 1)
            return null;
        
        int len = getLen(head);
        
        if(len < n)
            return null;
        Node runner = head;
        for(int i=1;i<len-n+1;i++)
            runner = runner.next;
        return runner;
    }
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    
    public static void main(String[] args){
        /* Start with the empty list. */
        LinkedList llist = new LinkedList();
 
        llist.head  = new Node(1);
        Node second = new Node(1);
        Node third  = new Node(3);
        Node fourth = new Node(4);
        llist.head.next = second; // Link first node with the second node
 
        second.next = third; // Link second node with the third node
        third.next = fourth;
        llist.printList();
        System.out.println("Length of list: "+getLen(llist.head));
        System.out.println("First from end: "+nthToLast(llist.head,1).data);
        System.out.println("Third from end: "+nthToLast(llist.head,3).data);
        System.out.println("First from end: "+nthToLast2(llist.head,1).data);
        System.out.println("Third from end: "+nthToLast2(llist.head,3).data);
        deleteDups2(llist.head);
        llist.printList();

    }
}