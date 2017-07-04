//Single LinkedList Implementation and problems

#include <iostream>
using namespace std;

class node {
    
  public:
  int data;
  node *next;
  
  
  node(int v,node *n=0){
      data=v;
      next=n;
  }
};

class list
{
    public:
    node *head;
    list(){
        head=NULL;
    }
    void insertAtEnd(int x);
    void insertAtHead(int x);
    void insertAtPos(int x,int pos);
    
    void deleteAtEnd();
    void deleteAtHead();
    void deleteAtPos(int pos);
    
    void traverse();
    
    void deleteList();
    int lengthOfList();
    
    //problems
    void sortList();
    void sortedInsert(int el);
    void sortedInsert2(node **, node *);
    void reverseIterative();
    node* reverseKGroup(node *,int);
    node* reverseRecursive(node *);
    
    node* nthNodeFromEnd(int n);
    void loopIntroduce();
    void removeDuplicates();
    node* new_node(int);
    int checkForLoop();
    int getNthNode(node *,int);
    int getMiddle(node*);
    int getNthNodeFromEnd(node*,int);
    
    
    
};

void list::insertAtHead(int x){
    node *tmp;
    if(head==NULL)
    head = new node(x);
    else {
        tmp = new node(x,head);
        head=tmp;
    } 
}

void list::traverse(){
    node *p=head;
    
    while(p){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

void list::insertAtEnd(int x){
    node *tmp;
    if(head==NULL)
    head=new node(x);
    else if(head->next==NULL)
    {
        tmp=new node(x);
        head->next=tmp;
    }
    else {
        node *p=head;
        while(p->next){
            p=p->next;
        }
        tmp=new node(x);
        p->next=tmp;
    }
}
int list::lengthOfList(){
    node *p=head;
    int len=0;
    while(p){
        p=p->next;
        len++;
    }
    
    return len;
}

void list::insertAtPos(int x,int pos){
    node *tmp;
    int k=1;
    tmp = new node(x);
    if(pos==1)
    {
        tmp->next=head;
        head=tmp;
    }
    else
    {
        node *p=head;
        node *q;
        while(p && k<pos){
            q=p;
            p=p->next;
            k++;
        }
        q->next=tmp;
        tmp->next=p;
    }
    
}
void list::deleteAtHead(){
    if(head==NULL)
    cout<<"List is empty\n";
    else 
    {
        node *tmp=head;
        head=head->next;
        delete tmp;
    }
    
    
}

void list::deleteAtEnd(){
    if(head==NULL)
    cout<<"List is empty\n";
    else if(head->next==NULL)
    {
    delete head;
    head=NULL;
    }
    else
    {
        node *p=head;
        node *q;
        while(p->next){
            q=p;
            p=p->next;
        }
        
        q->next=0;
        delete p;
    }
}

void list::deleteAtPos(int pos){
    int k=1;
    node *tmp;
    if(pos==1){
        tmp=head;
        head=head->next;
        delete tmp;
    }
    else 
    {
        node *p=head;
        node *q;
        while(p && k<pos){
            q=p;
            p=p->next;
            k++;
        }
        if(p==NULL)
        cout<<"Position doesnt exist\n";
        else
        {
            
        tmp=p;
        q->next=p->next;
        delete tmp;
            
        }
        
    }
}
void list::deleteList(){
    node *itr=head;
    node *aux;
    while(itr){
        aux=itr->next;
        delete itr;
        itr=aux;
    }
    head=NULL;
}



//problems
void list::reverseIterative()
{
    
    node *p=head;
    node *q;
    node *r=0;
    while(p){
        q=p;
        p=p->next;
        q->next=r;
        r=q;
        
    }
    head=r;
}

node* list::reverseRecursive(node *head){
    if(head==0 || head->next==0)
    return head;
    
    node *second=head->next;
    head->next=0;
    node *rest=reverseRecursive(second);
    second->next=head;
    return rest;
    
}

node* list::nthNodeFromEnd(int n){
    node *pnthNode=0;
    node *ptemp=head;
    for(int i=1;i<n;i++)
        if(ptemp)
            ptemp=ptemp->next;
    while(ptemp){
        if(pnthNode==0)
            pnthNode=head;
        else pnthNode=pnthNode->next;
        ptemp=ptemp->next;
    }
    if(pnthNode)
    return pnthNode;

    return NULL;
}


void list::loopIntroduce(){
    node *p=head;
    while(p->next)
        p=p->next;
    p->next=head;
}

int list::checkForLoop(){
    node *slow=head;
    node *fast=head;
    
    while(slow && fast && fast->next){
        
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return 1;
    }
    
    return 0;
}

void list::sortedInsert(int el){
    node *tmp;
    if(head==NULL)
        head=new node(el);
    else if(el <= head->data)
        {
            tmp=new node(el,head);
            head=tmp;
        }
    else{
        node *p=head;
        tmp=new node(el);
        while(p->next && el > p->next->data)
        {
            p=p->next;
        }
        tmp->next=p->next;
        p->next=tmp;
        
    }    
}
/* Memory efficient solution */
void list::sortedInsert2(node **head_ref, node *new_node){
    
    if (head_ref == NULL || new_node == NULL) return ;
    node **cursor = head_ref;
    while (*cursor && (*cursor)->data < new_node->data)
        cursor = &((*cursor)->next);
    new_node->next = *cursor;
    *cursor = new_node;
}

node* list::new_node(int n)
{
    node *tmp = new node(n);
    if (tmp == NULL) return NULL;
    return tmp;
}
int list::getNthNode(node *head,int n){
    node *itr=head;
    
    int count=0;
    
    while(itr){
        if(count==n-1)
        return itr->data;
        count++;
        itr=itr->next;
    }
    
    
    return -1;
    
}

int list::getMiddle(node *head){
    node *slow=head;
    node *fast=head;
    
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow->data;    
}

int list::getNthNodeFromEnd(node *head,int n){
    node *ref=head;
    node *main=head;
    int count=0;
    if(head){
        while(count<n)
        {
        if(ref==NULL)
            return -1;
        ref=ref->next;
        count++;    
        }
    }
    
    while(ref){
        main=main->next;
        ref=ref->next;
    }
    
    return main->data;
}
void list::removeDuplicates(){
    node *current=head;
    
    node *next_next;
    
    if(current==NULL)
    return;
    
    while(current->next){
        
        if(current->data==current->next->data)
        {
            next_next=current->next->next;
            delete(current->next);
            current->next=next_next;
        }
        else current=current->next;
        
    }
}

node* list::reverseKGroup(node *head,int k){
    int i=0;
    node *p=head;
    while(p && i<k)
        p=p->next,i++;
    if(i<k)return head;
    node *t=head->next;
    head->next=reverseKGroup(p,k);
    while(--i)
        p=t->next, t->next=head, head=t, t=p;
    return head;
}



/*
Given a linked list of 0s, 1s and 2s, sort it.
*/
void list::sortList()
{
    int count[3]={0};
    
    node *ptr=head;
    
    while(ptr){
        count[ptr->data]++;
        ptr=ptr->next;
    }
    
    int i=0;
    ptr=head;
    while(ptr)
    {
        if(count[i]==0)
            ++i;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;   
        }
    }
    
}

int main() {
    
/*    
   insertAtHead(1);
   insertAtHead(2);
   insertAtHead(3);
   traverse();
   cout<<"Length : "<<lengthOfList()<<endl;
   insertAtEnd(4);
   insertAtEnd(5);
   insertAtEnd(6);
   traverse();
   cout<<"Length : "<<lengthOfList()<<endl;
   insertAtPos(7,1);
   traverse();
   insertAtPos(8,4);
   traverse();    
   insertAtPos(9,11);
   traverse();
   cout<<"Length : "<<lengthOfList()<<endl;
   deleteAtHead();
   traverse();
   cout<<"Length : "<<lengthOfList()<<endl;
   deleteAtEnd();
   traverse();
   
   deleteAtPos(5);
   traverse();
   //deleteList();
   //traverse();
   reverseIterative();
   traverse();
   head=reverseRecursive(head);
   traverse();
   */
   /*
   insertAtEnd(1);
   insertAtEnd(2);
   insertAtEnd(3);
   insertAtEnd(4);
   insertAtEnd(5);
   insertAtEnd(6);
   traverse();
   cout<<nthNodeFromEnd(2)->data<<endl;
   loopIntroduce();
   if(checkForLoop())
   cout<<"Yes loop is present\n";
   else cout<<"No\n";
   */
   /*
   sortedInsert(3);
   sortedInsert(2);
   sortedInsert(1);
   traverse();
   sortedInsert(9);
   sortedInsert(8);
   sortedInsert(7);
   traverse();   
   sortedInsert2(&head,new_node(0));
   traverse();
   sortedInsert2(&head,new_node(5));
   traverse();
   
   cout<<"\nGet Nth Node : "<<getNthNode(head,2);
   cout<<"\nMiddle Node : "<<getMiddle(head);
   cout<<"\nGet Nth Node From End : "<<getNthNodeFromEnd(head,2)<<endl;
   
   
   sortedInsert(3);
   sortedInsert(7);
   traverse();
   removeDuplicates();
   traverse();
   
   head=reverseKGroup(head,3);
   traverse();
   
   */
   
   list l1;
   for(int i=0;i<5;i++)
   l1.insertAtEnd(i%3);
   l1.traverse();
   
   //l1.sortList();
   
   //l1.traverse();
   l1.head = l1.reverseKGroup(l1.head,6);
   l1.traverse();
   
}
