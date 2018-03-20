/*
2.1 Write code to remove duplicates from an unsorted linked list.
    FOLLOW UP
    How would you solve this problem if a temporary buffer is not allowed?
    
2.2 Implement an algorithm to find the nth to last element of a singly linked list.

2.3 Implement an algorithm to delete a node in the middle of a single linked list, given
    only access to that node.
    EXAMPLE
    Input: the node ‘c’ from the linked list a->b->c->d->e
    Result: nothing is returned, but the new linked list looks like a->b->d->e
    
2.4 You have two numbers represented by a linked list, where each node contains a single
    digit. The digits are stored in reverse order, such that the 1’s digit is at the head of
    the list. Write a function that adds the two numbers and returns the sum as a linked
    list.
    EXAMPLE
    Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
    Output: 8 -> 0 -> 8

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
        public void setNext(Node n){
            next = n;
        }
    }
    
    public void append(int new_data){
        /* 1. Allocate the Node &
        2. Put in the data
        3. Set next as null */
        Node new_node = new Node(new_data);
     
        /* 4. If the Linked List is empty, then make the
               new node as head */
        if (head == null)
        {
            head = new Node(new_data);
            return;
        }
     
        /* 4. This new node is going to be the last node, so
             make next of it as null */
        new_node.next = null;
     
        /* 5. Else traverse till the last node */
        Node last = head; 
        while (last.next != null)
            last = last.next;
     
        /* 6. Change the next of last node */
        last.next = new_node;
        return;
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
    
    public static boolean deleteNode(Node node){
        if(node == null || node.next == null){
            return false;
        }
        Node next = node.next;
        node.data = next.data;
        node.next = next.next;
        return true;
    }
    /*
    Time Complexity: O(1)
    Space Complexity: O(1)
    */
    public static Node addLists(Node l1, Node l2, int carry){
        
        if(l1 == null && l2 == null)
            return null;
            
        Node result = new Node(carry);
        int value = carry;
        if(l1 != null)
            value+=l1.data;
        if(l2 != null)
            value+=l2.data;
        result.data = value%10;
        
        Node more =  addLists(l1 == null ? null : l1.next, l2 == null ? null : l2.next, value > 9 ? 1 : 0);
        
        result.setNext(more);
        return result;
    }
    /*
    Time Complexity: O(m+n)
    */
    
    /*
    Wrapper method to perform addition of lists
    */
    public static Node addLists(Node l1, Node l2){
        return addLists(l1, l2, 0);
    }
    
    
    public static void main(String[] args){
        /* Start with the empty list. */
        /*
        LinkedList llist = new LinkedList();
 
        llist.head  = new Node(1);
        Node second = new Node(1);
        Node third  = new Node(3);
        Node fourth = new Node(4);
        Node fifth = new Node(5);
        llist.head.next = second; // Link first node with the second node
 
        second.next = third; // Link second node with the third node
        third.next = fourth;
        fourth.next = fifth;
        llist.printList();
        System.out.println("Length of list: "+getLen(llist.head));
        System.out.println("First from end: "+nthToLast(llist.head,1).data);
        System.out.println("Third from end: "+nthToLast(llist.head,3).data);
        System.out.println("First from end: "+nthToLast2(llist.head,1).data);
        System.out.println("Third from end: "+nthToLast2(llist.head,3).data);
        deleteDups2(llist.head);
        llist.printList();
        deleteNode(llist.head.next);
        llist.printList();
        */
        
        LinkedList l1 = new LinkedList();
        l1.append(3);
        l1.append(1);
        l1.append(5);
        //3->1->5->NULL which is actually 513 in base 10
        l1.printList();
        LinkedList l2 = new LinkedList();
        l2.append(5);
        l2.append(9);
        l2.append(2);
        //5->9->2->NULL which is actually 295 in base 10
        l2.printList();
        
        Node newHead = addLists(l1.head, l2.head);
        LinkedList l3 = new LinkedList();
        l3.head = newHead;
        l3.printList();
        
        
        
    }
}