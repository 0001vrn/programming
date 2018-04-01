/*
Implement two stacks in an array

Method 1 (Divide the space in two halves)
    A simple way to implement two stacks is to divide the array in two halves and assign the half half space to two stacks
    , i.e., use arr[0] to arr[n/2] for stack1, and arr[n/2+1] to arr[n-1] for stack2 where arr[] is the array to be used to 
    implement two stacks and size of array be n.
    
Method 2 (A space efficient implementation)
    This method efficiently utilizes the available space. It doesn’t cause an overflow if there is space available in arr[]. 
    The idea is to start two stacks from two extreme corners of arr[]
*/

#include <iostream>
#include<stdlib.h> // for exit()
using namespace std;

class TwoStacks{
    
    int *arr;
    int size;
    int top1;
    int top2;
    
    public:
    TwoStacks(int n){
        size=n;
        arr = new int[size];
        top1=-1;
        top2=size;
    }
    
    void push1(int x){
        if(top1 < top2 - 1)
        {
            top1++;
            arr[top1]=x;
        }
        else
        {
            cout<<"Stack Overflow\n";
            exit(1);
        }
    }
    
    void push2(int x){
        if(top1 < top2 - 1)
        {
            top2--;
            arr[top2]=x;
        }
        else
        {
            cout<<"Stack Overflow\n";
            exit(1);
        }
    }
    
    int pop1(){
        if(top1<0)
        {
            cout<<"Stack Underflow\n";
            exit(1);
        }
        else
        {
            int el = arr[top1];
            top1--;
            return el;
        }
    }
    
    int pop2(){
        if(top2>size)
        {
            cout<<"Stack Underflow\n";
            exit(1);
        }
        else
        {
            int el = arr[top2];
            top2++;
            return el;
        }
    }
};

int main(void){
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
    return -1;
}