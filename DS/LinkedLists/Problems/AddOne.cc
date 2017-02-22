//Program to implement addition of number 1 to linked list

#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node *next;
  
  node(int d=0,node *n=0){
      data=d;
      next=n;
  }
    
};

node * createNode(int x){
    node *tmp=new node(x);
    return tmp;
}
void traverse(node *head){
    node *p=head;
    while(p){
        cout<<p->data<<"->";
        p=p->next;
    }
    
    cout<<"NULL\n";
    
}

node *reverseIterative(node *head){
    node *p=head;
    node *q;
    node *r=0;
    while(p){
        q=p;
        p=p->next;
        q->next=r;
        r=q;
        
    }
    return r;
}


/* Adds one to a linked lists and return the head
   node of resultant list */
node *addOneUtil(node *head)
{
    // res is head node of the resultant list
    node* res = head;
    node *temp;
 
    int carry = 1, sum;
 
    while (head != NULL) //while both lists exist
    {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i) Carry
        // (ii) Next digit of head list (if there is a
        //     next digit)
        sum = carry + head->data;
 
        // update carry for next calulation
        carry = (sum >= 10)? 1 : 0;
 
        // update sum if it is greater than 10
        sum = sum % 10;
 
        // Create a new node with sum as data
        head->data = sum;
 
        // Move head and second pointers to next nodes
        temp = head;
        head = head->next;
    }
 
    // if some carry is still there, add a new node to
    // result list.
    if (carry > 0)
        temp->next = createNode(carry);
 
    // return head of the resultant list
    return res;
}
node *addOne(node *head){
    
    head=reverseIterative(head);
    
    head=addOneUtil(head);
    
    return reverseIterative(head);
    
    
}
int main(){
    node *head=NULL;
    
    head=createNode(9);
    head->next=createNode(9);
    head->next->next=createNode(8);
    
    traverse(head);
    
    head=addOne(head);
    
    traverse(head);
    
    head=addOne(head);
    
    traverse(head);
    return 0;
}