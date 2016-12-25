#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node *prev;
    
    node(int v,node *n=0,node *p=0){
        data=v;
        next=n;
        prev=p;
    }
}*head;
//implementation
void insertAtHead(int x){
    if(head==NULL)
        head=new node(x);
    else 
    {
        node *tmp=new node(x,head);
        head->prev=tmp;
        head=tmp;
    }
}
void traverse(){
    node *p=head;
    
    while(p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;    
}

void insertAtEnd(int x){
    if(head==NULL)
    head=new node(x);
    else {
        node *p=head;
        while(p->next)
            p=p->next;
        node *tmp=new node(x,0,p);
        p->next=tmp;
    }
}

void insertAtPos(int x,int pos){
    int k=1;
    node *tmp=new node(x);
    if(pos==1){
        tmp->next=head;
        head=tmp;
    }
    else
    {
        node *p=head;
        node *q;
        while(k<pos && p)
            {
                q=p;
                p=p->next;
                k++;
            }
            
        q->next=tmp;
        tmp->prev=q;
        tmp->next=p;
        if(p)
        p->prev=tmp;
        
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
        p->prev=0;
        delete p;
    }
}

void deleteAtPos(int pos){
    int k=1;
    node *tmp;
    if(pos==1){
        tmp=head;
        head=head->next;
    }
    else
    {
        node *p=head;
        node *q;
        while(k<pos && p)
            {
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
            if(p->next)
                p->next->prev=q;
            delete tmp;
            }
    }
    
}
int main(){
        
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    traverse();
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);
    traverse();
    insertAtPos(8,1);
    insertAtPos(9,8);
    traverse();
    deleteAtEnd();
    deleteAtEnd();
    traverse();
    deleteAtPos(1);
    deleteAtPos(6);
    traverse();
    return 0;
}