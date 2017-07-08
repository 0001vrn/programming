#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

ulli countSetBits(ulli n){
    ulli count=0;
    while(n){
        count+=n&1;
        n>>=1;
    }
    return count;
}
/*
    Time Complexity : theta(logn)
*/


ulli BrianKernighan(ulli n){
    ulli count=0;
    while(n){
        n&=(n-1);
        count++;
    }
    return count;
}
/*
    Time Complexity : O(logn)
*/


int main(void){
    
    ulli n = 15;
    cout<<countSetBits(n)<<endl;
    cout<<BrianKernighan(n)<<endl;
    
    
    //inbuilt function
    cout << __builtin_popcount (4) << endl;
    cout << __builtin_popcount (15) << endl;
    return 0;
}