/*
Q1 Search an element in a sorted and rotated array 

Ans

Solution 1:
Idea is to use binarySearch
    1. Find pivot point
    2. Divide the array in two sub-arrays
    3. call binary search

The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array, pivot element is the only element for which next element to it is smaller than it.

Solution 2:
We can search an element in one pass of Binary Search.


Q2 How to find the minimum element in a rotated array? e.g. 4 5 6 1 2 3

*/
#include<iostream>
using namespace std;

int pivotedBinarySearch(int arr[], int n, int key);
int binarySearch(int arr[], int low, int high, int key);
int findPivot(int arr[], int low, int high);
void secondInput();
int search(int arr[], int l, int h, int key);
void demoSearchMinInRotatedArray();

int main(void){
    
    // Let us search 3 in below array
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 3;
    
    // Function calling
    //cout << "Index of the element is : " << pivotedBinarySearch(arr, n, key)<<'\n';
     
    //secondInput();
    
    demoSearchMinInRotatedArray();

    return 0;
}

void demoSearchMinInRotatedArray(){
    //int arr[] = {4,5,6,1,2,3};
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pivot = findPivot(arr,0,n-1);
    cout<<"Min element in rotated array: ";
    if(pivot==-1)
        cout<<arr[0];
    else
        cout<<arr[pivot+1];
    cout<<'\n';
}
void secondInput(){
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 6;
    int i = search(arr, 0, n-1, key);
 
    if (i != -1)
    cout << "Index: " << i << endl;
    else
    cout << "Key not found";
}

int search(int arr[], int l, int h, int key){
    
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


int pivotedBinarySearch(int arr[], int n, int key){
    
    int pivot = findPivot(arr, 0, n-1);
    
    if(pivot == -1)
        return binarySearch(arr, 0, n-1, key);
    
    if(arr[pivot] == key)
        return pivot;
    
    if(arr[0]<=key)
        return binarySearch(arr, 0, pivot-1, key);
    
    return binarySearch(arr, pivot+1, n-1, key);
}
// Time Complexity: O(logn)

int findPivot(int arr[], int low, int high){
    
    if(high < low) return -1;
    if(high == low) return low;
    
    int mid = low + (high-low)/2;
    
    if(mid<high && arr[mid]>arr[mid+1])
        return mid;
        
    if(mid>low && arr[mid]<arr[mid-1])
        return mid-1;
        
    if(arr[low]>=arr[mid])
        return findPivot(arr, low, mid-1);
    
    return findPivot(arr, mid+1, high);
}

int binarySearch(int arr[], int low, int high, int key){
    
    if(high<low) return -1;
    
    int mid = low + (high-low)/2;
    
    if(arr[mid]==key)
        return mid;
    
    if(key > arr[mid])
        return binarySearch(arr, mid+1, high, key);
    
    return binarySearch(arr, low, mid-1, key);
}
