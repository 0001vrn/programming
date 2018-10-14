#include<iostream>
#include "queue.cc"
using namespace std;
int main(void){
    
    Queue *q = createQueue(); 
    q->enQueue(q, 10); 
    q->enQueue(q, 20); 
    q->deQueue(q); 
    q->deQueue(q); 
    q->enQueue(q, 30); 
    q->enQueue(q, 40); 
    q->enQueue(q, 50); 
    QNode *n = q->deQueue(q); 
    if (n != NULL) 
      printf("Dequeued item is %d", n->key); 
    return 0; 
    
    
    return 0;   
}