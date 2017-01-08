//implementation of Unrolled Linked Lists
#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    vector<int> v;
    node *next;
};

void traverse(node *n){
    while(n!=NULL){
        for(int i=0;i<n->v.size();i++)
            printf("%d->",n->v[i]);
        
        n=n->next;
    }
    printf("NULL");
}


int main(){
    node *head=NULL;
    node *second=NULL;
    node *third=NULL;
    
    head=new node;
    second=new node;
    third=new node;
    
    head->v.push_back(1);
    head->v.push_back(2);
    head->v.push_back(3);
    
    head->next=second;
    
    second->v.push_back(4);
    second->v.push_back(5);
    second->v.push_back(6);
    
    second->next=third;
    
    third->v.push_back(7);
    third->v.push_back(8);
    third->v.push_back(9);
    
    traverse(head);
    
    return 0;
}

//implementation of Unrolled Linked Lists
/*
#include<iostream>
using namespace std;
#define maxElements 4

class node{
    public:
    int numElements;
    int arr[maxElements];//use vector if you want variable size array
    node *next;
};

void traverse(node *n){
    while(n!=NULL){
        for(int i=0;i<n->numElements;i++)
            printf("%d->",n->arr[i]);
        
        n=n->next;
    }
    printf("NULL");
}


int main(){
    node *head=NULL;
    node *second=NULL;
    node *third=NULL;
    
    head=new node;
    second=new node;
    third=new node;
    
    head->numElements=3;
    head->arr[0]=1;
    head->arr[1]=2;
    head->arr[2]=3;
    
    head->next=second;
    
    second->numElements=3;
    second->arr[0]=4;
    second->arr[1]=5;
    second->arr[2]=6;
    
    second->next=third;
    
    third->numElements=3;
    third->arr[0]=7;
    third->arr[1]=8;
    third->arr[2]=9;
    
    traverse(head);
    
    return 0;
}*/