#include<iostream>
using namespace std;


template <class t>
class node{
  public:
  t data;
  node *next;
};
template <class t>
class stack{
    public:
    node<t> *head;
    stack(){
        head=NULL;
    }
    void push(t x){
        
        if(head==NULL){
            head=new node<t>;
            head->data=x;
            head->next=NULL;
        }
        else
        {
            node<t> *tmp=new node<t>;
            tmp->data=x;
            tmp->next=head;
            head=tmp;
        }
        
    }
    
    t pop(){
        if(head==NULL)
        return -1;
        else
        {
            int el=head->data;
            node<t> *tmp=head;
            head=head->next;
            delete tmp;
            return el;
        }
    }
    
    bool isEmpty(){
        return head==NULL;
    }
};



class stackUsingArray
{
  public:
    int *arr;
    int top;
    int size;
    stackUsingArray(int cap){
        size=cap;
        arr=new int[cap];
        top=-1;
    }
    
    void push(int x){
        if(top==size-1)
            return;
        else 
          arr[++top]=x;  
        
    }
    
    int pop(){
        if(top==-1)
        return -1;
        else{
            int el=arr[top];
            top--;
            return el;
        }
        
    }
    int getSize(){
        return size;
    }
    
    bool isEmpty(){
        return top==-1;
    }
};



int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    
    cout<<s.isEmpty()<<endl;
    
    stack<char> s2;
    s2.push('a');
    s2.push('b');
    s2.push('c');
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    
    cout<<s.isEmpty()<<endl;
    stackUsingArray s1(3);
    
    s1.push(1);
    s1.push(2);
    s1.push(33);
    cout<<s1.getSize()<<endl;
    cout<<s1.pop()<<endl;
    // cout<<s1.pop()<<endl;
    // cout<<s1.pop()<<endl;
    cout<<s1.isEmpty()<<endl;
    
    return 0;
}