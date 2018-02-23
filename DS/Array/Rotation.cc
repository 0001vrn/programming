#include <iostream>
#include <algorithm> 

using namespace std;

void rotate(int arr[], int n, int d);
void print(int arr[], int n);

/*Function to left Rotate arr[] of size n by d*/
void leftRotate(int arr[], int n, int d);
/*Function to left Rotate arr[] of size n by 1*/
void leftRotateByOne(int arr[], int n);

void leftRotateExtended(int arr[], int n, int d);

void rotate2(int arr[], int n, int d);
void rvereseArray(int arr[], int start, int end);

//Given an array, cyclically rotate the array clockwise by one.
void cyclicRotate(int arr[], int n);
//Given an array, cyclically rotate the array anti-clockwise by one.
void rcyclicRotate(int arr[], int n);


int findPivot(int[], int, int);
int binarySearch(int[], int, int, int);
 
//Searches an element key in a pivoted sorted array arr[] of size n
int pivotedBinarySearch(int arr[], int n, int key);

int search(int arr[], int l, int h, int key);


int main(void)
{
    
   int arr[]={1,2,3,4,5,6,7,8};
   int n = sizeof(arr)/sizeof(arr[0]);
   
   print(arr,n);
   
   //method 1 
   //use temp array
  
   //by d elements
   int d = 2; 
   
   //method 1
   //left rotate one by one
   
   //method 1
   //rotate(arr,n,d);
   
   //method 2
   //leftRotate(arr,n,d);
   
   //method 3
   //A Juggling Algorithm - Extension of Method 2
   
   //leftRotateExtended(arr,n,d);
  
  
   //method 4 The reversal algorithm
   
   rotate2(arr,n,d);
   print(arr,n);
   
   
   cyclicRotate(arr,n);
   print(arr,n);
   
   /* function to search an element in a sorted and pivoted array*/
   //method 1 - pivotedBinarySearch
   int keyToSearch = 1;
   cout<<"Index of "<<keyToSearch<<" is : "<<pivotedBinarySearch(arr,n,keyToSearch)<<'\n';
   
   //method 2
   //search in one pass of Binary Search
   cout<<"Index of "<<keyToSearch<<" is : "<<search(arr,0,n-1,keyToSearch)<<'\n';

   
   
   rcyclicRotate(arr,n);
   print(arr,n);
   
   return 0; 
}
// Returns index of key in arr[l..h] if key is present,
// otherwise returns -1
int search(int arr[], int l, int h, int key)
{
    if (l > h) return -1;
 
    int mid = (l+h)/2;
    if (arr[mid] == key) return mid;
 
    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid])
    {
        /* As this subarray is sorted, we can quickly
           check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])
           return search(arr, l, mid-1, key);
 
        return search(arr, mid+1, h, key);
    }
 
    /* If arr[l..mid] is not sorted, then arr[mid... r]
       must be sorted*/
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid+1, h, key);
 
    return search(arr, l, mid-1, key);
}
//Time Complexity : O(logn)

int findPivot(int arr[], int low, int high)
{
    if(high<low)
        return -1;
    if (high == low) return low;
    
    int mid = low + (high-low)/2;
    
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid-1);
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid-1);
  
    return findPivot(arr, mid + 1, high);
}
int pivotedBinarySearch(int arr[], int n, int key)
{
    int pivot = findPivot(arr,0,n-1);
    
    if(pivot == -1)
        return binarySearch(arr,0,n-1,key);
        
    if(arr[pivot] == key)
        return pivot;
    
    if(arr[0]<=key)
        return binarySearch(arr,0,pivot-1,key);
        
    return binarySearch(arr,pivot+1,n-1,key);
}
//Time Complexity : O(logn)

int binarySearch(int arr[], int low, int high, int key)
{
    if(high<low)
        return -1;
    int mid = low + (high-low)/2;
    
    if(key == arr[mid])
        return mid;
        
    if(key < arr[mid])
        return binarySearch(arr,low,mid-1,key);
    else 
        return binarySearch(arr,mid+1,high,key);
}
//Time Complexity : O(logn)


void rcyclicRotate(int arr[], int n)
{
    int x = arr[0];
    for(int i=0;i<n-1;i++)
        arr[i]=arr[i+1];
    arr[n-1]=x;
}
//Time complexity: O(n)
//Auxiliary Space: O(1)

void cyclicRotate(int arr[], int n)
{
   
    int x = arr[n-1];
    for(int i=n-1;i>0;i--)
        arr[i]=arr[i-1];
    arr[0]=x;
}
//Time complexity: O(n)
//Auxiliary Space: O(1)


//method 4 (The reversal algorithm)
void rotate2(int arr[], int n, int d){
    
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
    
    /*
    rvereseArray(arr,0,d-1);
    rvereseArray(arr,d,n-1);
    rvereseArray(arr,0,n-1);
    */
}
//Time complexity: O(n)
//Auxiliary Space: O(1)



/*Function to reverse arr[] from index start to end*/
void rvereseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
//method 3
void leftRotateExtended(int arr[], int n, int d)
{
    int i, j, k, temp;
    for (i = 0; i < __gcd(d, n); i++)
    {
    /* move i-th values of blocks */
    temp = arr[i];
    j = i;
    while(1)
        {
          k = j + d;
          if (k >= n)
            k = k - n;
          if (k == i)
            break;
          arr[j] = arr[k];
          j = k;
        }
    arr[j] = temp;
    }
}
//Time complexity: O(n)
//Auxiliary Space: O(1)



//method 2
//left rotate one by one
void leftRotate(int arr[], int n, int d)
{
    for(int i=0;i<d;i++)
        leftRotateByOne(arr,n);
}
void leftRotateByOne(int arr[], int n)
{
    int i,temp = arr[0];
    for(i=0;i<n-1;i++)
        arr[i]=arr[i+1];
    arr[i]=temp;
}

//Time complexity: O(n*d)
//Auxiliary Space: O(1)



//method 1 
//use temp array
void rotate(int arr[], int n, int d)
{
    int temp[d];
    
    for(int i=0;i<d;i++)
        temp[i]=arr[i];
    
    for(int i=0;i<n-d;i++)
        arr[i]=arr[i+d];
    
    for(int i=0;i<d;i++)
        arr[n-d+i] = temp[i];
}

//Time complexity O(n)
//Auxiliary Space: O(d)


void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
}

