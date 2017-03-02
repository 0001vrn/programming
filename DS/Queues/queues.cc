#include<iostream>
using namespace std;

template<class t>
class node {
  public:
  t data;
  node *next;
};

template<class t>
class queue
{
  public:
  node<t> *front,*rear;
  queue(){
      front=rear=NULL;
  }
  void push(t x);
  t pop();
  bool isEmpty();
  
};

template<class t>
void queue<t>::push(t x){
  node<t> *tmp=new node<t>;
  tmp->data=x;
  tmp->next=NULL;

if(rear)
    rear->next=tmp;
rear=tmp;
    
if(front==NULL)
front=rear;
    
}
  
template<class t>
t queue<t>::pop(){
  
  if(isEmpty()){
      return -1;
  }
  else
  {
  t el=front->data;
  node<t> *tmp=front;
  front=front->next;
  delete tmp;
  return el;
      
  }
}
  
template<class t>
bool queue<t>::isEmpty(){
  return front==NULL;
}
#define MAX_SIZE 50
class queueUsingArray{
    public:
    int front,rear;
    int arr[MAX_SIZE];
    queueUsingArray(){
        front=rear=-1;
    }
    bool isFull(){
        return ((rear+1 % MAX_SIZE)==front);
    }
    
    bool isEmpty(){
        return front==-1;
    }
    void push(int x){
        if(isFull())
            printf("Overflow\n");
        else
        {
            rear=(rear+1)%MAX_SIZE;
            arr[rear]=x;
            if(front==-1)
                front=rear;
        }
        
    }
    
    int pop(){
        if(isEmpty())
        {
            printf("Underflow\n");
            return -1;
        }
        else
        {
            int el=arr[front];
            if(front==rear)
                front=rear=-1;
            else front=(front+1) % MAX_SIZE;
            
            return el;
        }
    }
};


int main(){
    
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    
    queue<double> q1;
    q1.push(1.2);
    q1.push(2.8);
    q1.push(3.7);
    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;
    
    queueUsingArray q3;
    q3.push(11);
    q3.push(12);
    q3.push(13);
    
    cout<<q3.pop()<<endl;
    cout<<q3.pop()<<endl;
    cout<<q3.pop()<<endl;
    cout<<q3.pop()<<endl;
    
    return 0;
}