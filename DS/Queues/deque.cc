#include<iostream>
using namespace std;

template <class t>
class node{
    public:
    t val;
    node<t> *next;
    node<t> *prev;
    node(t v,node *n=0,node *p=0){
        val=v;
        next=n;
        prev=p;
    }
};

template<class t>
class deque{
    public:
    node<t> *head,*tail;
    int count;
    deque(){
        head=tail=NULL;
        count=0;
    }
    
    void push_front(t el);
    void push_back(t el);
    void pop_front();
    void pop_back();
    
    t front();
    t rear();
    bool isEmpty();
    int size(){
        return count;
    }
    
    void print();
    
};

template<class t>
void deque<t>::push_front(t el){
    node<t> *tmp=new node<t>(el);
    if(isEmpty())
    {
        head=tail=tmp;
    }
    else
    {
        tmp->next=head;
        head->prev=tmp;
        head=tmp;
    }
    count++;
}

template<class t>
void deque<t>::push_back(t el){
    node<t> *tmp=new node<t>(el);
    if(isEmpty())
    {
        head=tail=tmp;
    }
    else
    {
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
    count++;
}
template<class t>
void deque<t>::pop_front(){
    if(head==NULL){
        printf("deque is empty\n");
        return;
    }
    node<t> *tmp=head;
    head=head->next;
    delete tmp;
    count--;
}

template<class t>
void deque<t>::pop_back(){
    if(tail==NULL){
        printf("deque is empty\n");
        return;
    }
    node<t> *tmp=tail;
    tail=tail->prev;
    delete tmp;
    count--;
    
}

template<class t>
t deque<t>::front(){
    if(head)
    return head->val;
    else return -1;
}

template<class t>
t deque<t>::rear(){
    if(tail)
    return tail->val;
    else return -1;
}

template<class t>
bool deque<t>::isEmpty(){
    return count == 0 ? true : false;
}

template<class t>
void deque<t>::print(){
    node<t> *p=head;
    
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<"\n";
}
int main(void){
    deque<char> dq;
    dq.push_front('1');
    dq.push_front('2');
    dq.push_back('3');
    dq.push_back('4');
    
    dq.print();
    //cout<<dq.isEmpty()<<endl;
    
    dq.pop_front();
    dq.print();
    cout<<dq.front()<<"\n";
    cout<<dq.rear()<<"\n";
    return 0;
}