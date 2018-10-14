//Single LinkedList Implementation and problems

#include <iostream>
using namespace std;

template <typename T> 
class node {
    
  public:
  T data;
  node *next;
  
  
  node(T v,node *n=0){
      data=v;
      next=n;
  }
};

template <typename T> 
class list
{
    public:
    node<T> *head;
    list(){
        head=NULL;
    }
    void insertAtEnd(T x);
    void insertAtHead(T x);
    void insertAtPos(T x,int pos);
    
    void deleteAtEnd();
    void deleteAtHead();
    void deleteAtPos(int pos);
    
    void traverse();
    
    void deleteList();
    int lengthOfList();
    
    //problems
    void sortList();
    void sortedInsert(T el);
    void sortedInsert2(node<T> **, node<T> *);
    void reverseIterative();
    node<T>* reverseKGroup(node<T> *,int);
    node<T>* reverseRecursive(node<T> *);
    
    node<T>* nthNodeFromEnd(int n);
    void loopIntroduce();
    void removeDuplicates();
    node<T>* new_node(T);
    int checkForLoop();
    int getNthNode(node<T> *,int);
    int getMiddle(node<T> *);
    int getNthNodeFromEnd(node<T> *,int);
    
    
    
};

template <typename T> 
void list<T>::insertAtHead(T x){
    node<T> *tmp;
    if(head==NULL)
    head = new node<T>(x);
    else {
        tmp = new node<T>(x,head);
        head=tmp;
    } 
}

template <typename T> 
void list<T>::traverse(){
    node<T> *p=head;
    
    while(p){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

template <typename T> 
void list<T>::insertAtEnd(T x){
    node<T> *tmp;
    if(head==NULL)
    head=new node<T>(x);
    else if(head->next==NULL)
    {
        tmp=new node<T>(x);
        head->next=tmp;
    }
    else {
        node<T> *p=head;
        while(p->next){
            p=p->next;
        }
        tmp=new node<T>(x);
        p->next=tmp;
    }
}

template <typename T> 
int list<T>::lengthOfList(){
    node<T> *p=head;
    int len=0;
    while(p){
        p=p->next;
        len++;
    }
    
    return len;
}

template <typename T> 
void list<T>::insertAtPos(T x,int pos){
    node<T> *tmp;
    int k=1;
    tmp = new node<T>(x);
    if(pos==1)
    {
        tmp->next=head;
        head=tmp;
    }
    else
    {
        node<T> *p=head;
        node<T> *q;
        while(p && k<pos){
            q=p;
            p=p->next;
            k++;
        }
        q->next=tmp;
        tmp->next=p;
    }
    
}

template <typename T> 
void list<T>::deleteAtHead(){
    if(head==NULL)
    cout<<"List is empty\n";
    else 
    {
        node<T> *tmp=head;
        head=head->next;
        delete tmp;
    }
    
    
}

template <typename T> 
void list<T>::deleteAtEnd(){
    if(head==NULL)
    cout<<"List is empty\n";
    else if(head->next==NULL)
    {
    delete head;
    head=NULL;
    }
    else
    {
        node<T> *p=head;
        node<T> *q;
        while(p->next){
            q=p;
            p=p->next;
        }
        
        q->next=0;
        delete p;
    }
}

template <typename T> 
void list<T>::deleteAtPos(int pos){
    int k=1;
    node<T> *tmp;
    if(pos==1){
        tmp=head;
        head=head->next;
        delete tmp;
    }
    else 
    {
        node<T> *p=head;
        node<T> *q;
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

template <typename T> 
void list<T>::deleteList(){
    node<T> *itr=head;
    node<T> *aux;
    while(itr){
        aux=itr->next;
        delete itr;
        itr=aux;
    }
    head=NULL;
}



//problems
template <typename T> 
void list<T>::reverseIterative()
{
    
    node<T> *p=head;
    node<T> *q;
    node<T> *r=0;
    while(p){
        q=p;
        p=p->next;
        q->next=r;
        r=q;
        
    }
    head=r;
}

template <typename T>
node<T>* list<T>::reverseRecursive(node<T> *head){
    if(head==0 || head->next==0)
    return head;
    
    node<T> *second=head->next;
    head->next=0;
    node<T> *rest=reverseRecursive(second);
    second->next=head;
    return rest;
    
}


template <typename T> 
node<T>* list<T>::nthNodeFromEnd(int n){
    node<T> *pnthNode=0;
    node<T> *ptemp=head;
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


template <typename T> 
void list<T>::loopIntroduce(){
    node<T> *p=head;
    while(p->next)
        p=p->next;
    p->next=head;
}

template <typename T> 
int list<T>::checkForLoop(){
    node<T> *slow=head;
    node<T> *fast=head;
    
    while(slow && fast && fast->next){
        
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return 1;
    }
    
    return 0;
}

template <typename T> 
void list<T>::sortedInsert(T el){
    node<T> *tmp;
    if(head==NULL)
        head=new node<T>(el);
    else if(el <= head->data)
        {
            tmp=new node<T>(el,head);
            head=tmp;
        }
    else{
        node<T> *p=head;
        tmp=new node<T>(el);
        while(p->next && el > p->next->data)
        {
            p=p->next;
        }
        tmp->next=p->next;
        p->next=tmp;
        
    }    
}
/* Memory efficient solution */
template <typename T> 
void list<T>::sortedInsert2(node<T> **head_ref, node<T> *new_node){
    
    if (head_ref == NULL || new_node == NULL) return ;
    node<T> **cursor = head_ref;
    while (*cursor && (*cursor)->data < new_node->data)
        cursor = &((*cursor)->next);
    new_node->next = *cursor;
    *cursor = new_node;
}


template <typename T> 
node<T>* list<T>::new_node(T n)
{
    node<T> *tmp = new node<T>(n);
    if (tmp == NULL) return NULL;
    return tmp;
}

template <typename T> 
int list<T>::getNthNode(node<T> *head,int n){
    node<T> *itr=head;
    
    int count=0;
    
    while(itr){
        if(count==n-1)
        return itr->data;
        count++;
        itr=itr->next;
    }
    
    
    return -1;
    
}

template <typename T> 
int list<T>::getMiddle(node<T> *head){
    node<T> *slow=head;
    node<T> *fast=head;
    
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow->data;    
}

template <typename T> 
int list<T>::getNthNodeFromEnd(node<T> *head,int n){
    node<T> *ref=head;
    node<T> *main=head;
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

template <typename T> 
void list<T>::removeDuplicates(){
    node<T> *current=head;
    
    node<T> *next_next;
    
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

template <typename T> 
node<T>* list<T>::reverseKGroup(node<T> *head,int k){
    int i=0;
    node<T> *p=head;
    while(p && i<k)
        p=p->next,i++;
    if(i<k)return head;
    node<T> *t=head->next;
    head->next=reverseKGroup(p,k);
    while(--i)
        p=t->next, t->next=head, head=t, t=p;
    return head;
}



/*
Given a linked list of 0s, 1s and 2s, sort it.
*/
template <typename T> 
void list<T>::sortList()
{
    int count[3]={0};
    
    node<T> *ptr=head;
    
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
   
   /*
   list<int> l1;
   for(int i=0;i<10;i++)
   l1.insertAtEnd(i%3);
   l1.traverse();
   
   //l1.sortList();
   
   //l1.traverse();
   l1.head = l1.reverseKGroup(l1.head,2);
   l1.traverse();
   l1.sortList();
   l1.traverse();
   */
   int arr[] = {3,2,1,0,5,4,6,9,8,7};
   list<int> l1;
   for(int i=0;i<10;i++)
        l1.sortedInsert(arr[i]);
   l1.traverse();
}
