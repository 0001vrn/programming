#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    
    node(int v,node *n=0){
        data=v;
        next=n;
    }
}*head;

//implementation
void insertAtEnd(int x){
    
    node *tmp =new node(x);
    tmp->next=tmp;//for single node i.e head points to itself
    
    if(head==NULL)
        head=tmp;
    else 
    {
        node *p=head;
        while(p->next!=head)
            p=p->next;
        
        tmp->next=head;
        p->next=tmp;
    }
    
}

void traverse(){
    node *p=head;
    
    while(p->next!=head)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<p->data<<"->NULL"<<endl;   
}

void insertAtHead(int x){
    node *tmp =new node(x);
    tmp->next=tmp;
    
    if(head==NULL)
        head=tmp;
    else 
    {
        node *p=head;
        while(p->next!=head)
            p=p->next;
        
        tmp->next=head;
        p->next=tmp;
        head=tmp;
    }
    
}

void deleteAtEnd(){
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    node *cur=head;
    node *tmp;
    while(cur->next!=head)
        {
            tmp=cur;
            cur=cur->next;
        }
        
    tmp->next=cur->next;
    
    delete cur;
}
void deleteAtHead(){
     if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    node *cur=head;
    node *tmp=head;
    while(cur->next!=head)
        cur=cur->next;
        
    cur->next=head->next;
    head=head->next;

    delete tmp;
}


int main(){
    deleteAtEnd();
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    traverse();
    insertAtHead(4);
    insertAtHead(5);
    insertAtHead(6);
    traverse();
    deleteAtEnd();
    deleteAtEnd();
    traverse();
    deleteAtHead();
    deleteAtHead();
    traverse();
    
    return 0;
}