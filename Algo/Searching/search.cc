#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key){
    int low=0;
    int high=n-1;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            low = mid+1;
        else high = mid-1;
    }
    
    return -1;
}

int binarySearchRecursive(int arr[],int low,int high,int key){
   
    int mid=low+(high-low)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]<key)
        return binarySearchRecursive(arr,mid+1,high,key);
    else 
        return binarySearchRecursive(arr,low,mid-1,key);

    return -1;
}

int unorderedLinearSearch(int arr[],int n,int data){
    for(int i=0;i<n;i++)
        if(arr[i]==data)
            return i;
    
    return -1;        
}

int orderedLinearSearch(int arr[],int n,int data){
    for(int i=0;i<n;i++)
        if(arr[i]==data)
            return i;
        else if(arr[i]>data)
            return -1;
    
    return -1;    
}
int main(void){
    
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int key=4;
    int idx=-1;
    if((idx = binarySearch(arr,n,key))>0)
        cout<<"\nElement found at index : "<<idx;
    else 
        cout<<"\nNot found ";
    
    
    if((idx = binarySearchRecursive(arr,0,n-1,key))>0)
        cout<<"\nElement found at index : "<<idx;
    else 
        cout<<"\nNot found ";
        
    if((idx = unorderedLinearSearch(arr,n,key))>0)
        cout<<"\nElement found at index : "<<idx;
    else 
        cout<<"\nNot found ";
        
    if((idx = orderedLinearSearch(arr,n,key))>0)
        cout<<"\nElement found at index : "<<idx;
    else 
        cout<<"\nNot found ";
        
    return 0;
}