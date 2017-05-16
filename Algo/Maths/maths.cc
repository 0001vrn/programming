#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
    
    for(int i=2;i<n;i++)
        if(n%i==0)
            return false;
    
    return true;
}

bool isPrime(int n){
    if(n<=1)
    return false;
    if(n==2)return true;
    int m=sqrt(n);
    
    for(int i=3;i<=m;i+=2)
        if(n%i==0)
            return false;
    
    return true;
}
vector<bool> sieve(int n){
   
    vector<bool> prime(n+1,true);
    prime[0]=false;
    prime[1]=false;
    int m=sqrt(n);
    for (int p=2; p<=m; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p])
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    return prime;
}
int gcdIterative(int a,int b){
    for (int i=min(a,b); i>=1; i--)
        if (a%i==0 && b%i==0)
            return i;
}

int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int main(void){
    
    cout<<prime(5)<<'\n';
    cout<<isPrime(5)<<'\n';
    int n=100;
    vector<bool> ans=sieve(n);
    for(int i=0;i<n;i++)
        if(ans[i])
            cout<<i<<' ';

    cout<<'\n';
    
    int a=10;
    int b=24;
    cout<<gcdIterative(a,b)<<'\n';
    cout<<gcd(a,b)<<'\n';
    cout<<lcm(a,b)<<'\n';
    
    return 0;
}