//Single LinkedList Implementation

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
}*head;

void insertAtHead(int x){
    node *tmp;
    if(head==NULL)
    head = new node(x);
    else {
        tmp = new node(x,head);
        head=tmp;
    } 
}

void traverse(){
    node *p=head;
    while(p){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtEnd(int x){
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
int lengthOfList(){
    node *p=head;
    int len=0;
    while(p){
        p=p->next;
        len++;
    }
    
    return len;
}

void insertAtPos(int x,int pos){
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
void deleteAtHead(){
    if(head==NULL)
    cout<<"List is empty\n";
    else 
    {
        node *tmp=head;
        head=head->next;
        delete tmp;
    }
    
    
}

void deleteAtEnd(){
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

void deleteAtPos(int pos){
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
void deleteList(){
    node *itr=head;
    node *aux;
    while(itr){
        aux=itr->next;
        delete itr;
        itr=aux;
    }
    head=NULL;
}
int main() {
    
    
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
   deleteList();
   traverse();
   
}
