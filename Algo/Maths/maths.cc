#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(cont) cont.begin(), cont.end()
typedef unsigned long long int ulli;
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
vector<ulli> sieve(int n){
   
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
    vector<ulli> ans;
    for(int i=0;i<n;i++)
        if(prime[i])
            ans.pb(i);
    return ans;
}
bool isZero (ulli i) 
{
    return i == 0;
}

vector<ulli> sieveRange(int start,int end){
    
    vector<ulli> s1 = sieve(start);
    vector<ulli> s2 = sieve(end);
    
    vector<ulli> ans(end-start);
    
    set_difference(all(s2),all(s1),ans.begin());
    vector<ulli>::iterator itr = remove_if(all(ans),isZero);
    ans.resize(itr-ans.begin());
    
    return ans;
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
    return (a*b)/gcd(a,b);
}
int main(void){
    
    cout<<prime(5)<<'\n';
    cout<<isPrime(5)<<'\n';
    int n=100;
    vector<ulli> ans=sieve(n);
    for(auto i:ans)
        cout<<i<<' ';
    cout<<'\n';
    
    int start=50;
    int end=100;
    ans.clear();
    ans=sieveRange(start,end);
    for(auto i:ans)
        cout<<i<<' ';
    cout<<'\n';
    
    int a=10;
    int b=24;
    cout<<gcdIterative(a,b)<<'\n';
    cout<<gcd(a,b)<<'\n';
    cout<<lcm(a,b)<<'\n';
    
    return 0;
}