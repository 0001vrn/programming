#include<bits/stdc++.h>
using namespace std;

#define RANGE 255

void countSort(char arr[]);

void radixSort(int arr[],int n);
int getMax(int a[],int n);
void countSortUtil(int a[],int n,int exp);

void bucketSort(float arr[],int n);

void print(char arr[]){
    for(int i=0;arr[i];i++)
        cout<<arr[i];
    cout<<'\n';
}
void print(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    
    cout<<'\n';
}

void print(float a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    
    cout<<'\n';
}
int main(void){
    
    //char arr[] = "geeksforgeeks";//"applepp";
    //countSort(arr);    
    //print(arr);

    // int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // radixSort(arr, n);
    // print(arr, n);
    
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
    print(arr,n);
    
    return 0;
}
void bucketSort(float arr[],int n){
    // 1) Create n empty buckets
    vector<float> b[n];
    
    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       b[bi].push_back(arr[i]);
    }
 
    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}
void countSort(char arr[]){
    char output[strlen(arr)];
    int count[RANGE+1]={0};
    int i;
    //memset(count,0,sizeof(count));
    // Store count of each character
    for(i = 0; arr[i]; ++i)
        ++count[arr[i]];
 
    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i-1];
 
    // Build the output character array
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
 
    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

void radixSort(int a[],int n){
    int m=getMax(a,n);
    
    for(int exp=1;m/exp>0;exp*=10)
        countSortUtil(a,n,exp);
}
int getMax(int a[],int n){
    int ans=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>ans)
            ans=a[i];
    
    return ans;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSortUtil(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}