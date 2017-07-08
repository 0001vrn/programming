/*

Count Inversions in an array | Set 1 (Using Merge Sort)
Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

*/
#include<bits/stdc++.h>
using namespace std;

//Method 1 (Simple)
int getInvCount(int arr[], int n)
{
    int count=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(arr[i]>arr[j])
                count++;
    return count;
}

// Time complexity : O(n^2)

//Method 2 (using Merge Sort)
int merge(int arr[], int tmp[], int l, int m, int r)
{
    int i,j,k;
    int count=0;
    i=l;
    j=m;
    k=l;
    
    while(i<=m-1 && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            tmp[k++]=arr[i++];    
        }
        else
        {
            tmp[k++] = arr[j++];
            /*this is tricky -- see above explanation/diagram for merge()*/
            count = count + (m - i);   
        }
    }
    
    /* Copy the remaining elements of left subarray
    (if there are any) to temp*/
    while (i <= m - 1)
        tmp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
    (if there are any) to temp*/
    while (j <= r)
        tmp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i=l; i <= r; i++)
        arr[i] = tmp[i];
 
    return count;
    
}

int _mergeSort(int arr[],int tmp[], int l, int r)
{
    int m;
    int count=0;
    if(l<r)
    {
        m = l+(r-l)/2;
        count= _mergeSort(arr, tmp, l, m);
        count+=_mergeSort(arr, tmp, m+1, r);
        
        count+=merge(arr, tmp, l, m+1, r);
    }
    
    return count;
}

int mergeSort(int arr[], int n)
{
    int *tmp = new int[n];
    return _mergeSort(arr,tmp,0,n-1);
}

// Time complexity : O(nlogn)

// Method 3 (using STL)
int getInvCountSTL(int arr[], int n)
{
    set<int> s;
    s.insert(arr[0]);
    
    set<int>::iterator itr;
    int invcount = 0;
    for(int i=1;i<n;i++)
    {
        // Insert arr[i] in set (Note that set maintains
        // sorted order)
        s.insert(arr[i]);
 
        // Set the iterator to first greater element than arr[i]
        // in set (Note that set stores arr[0],.., arr[i-1]
        itr = s.upper_bound(arr[i]);
 
        // Get distance of first greater element from end
        // and this distance is count of greater elements
        // on left side of arr[i]
        invcount += distance(itr, s.end());
    }
    
    return invcount;
}

// Time Complexity : O(n^2)




int main(void)
{
    
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf(" Number of inversions are : %d \n", getInvCountSTL(arr, n));
    printf(" Number of inversions are : %d \n", getInvCount(arr, n));
    printf(" Number of inversions are : %d \n", mergeSort(arr,n));

    
    return 0;
}
