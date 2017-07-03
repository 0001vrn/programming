/*

Fibonacci Numbers - Standard DP problem

The Fibonacci numbers are the numbers in the following integer sequence.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……

*/

#include<bits/stdc++.h>
using namespace std;
//recursion
int fib(int n){
    
    if(n<0)
        return -1;
    
    if(n<=1)
        return n;
    
    return fib(n-1)+fib(n-2);
}

/*
    Time Complexity
    
    O(exp)
    
    Recurrence relation
    T(n) = T(n-1) + T(n-2) which is exponential.
*/
int main(void){
    int n = 25;
    cout<<fib(n)<<endl;
    
    return 0;
}