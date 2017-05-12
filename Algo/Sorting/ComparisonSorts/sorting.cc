#include<iostream>
using namespace std;


void bubbleSort(int a[],int n);
void selectionSort(int a[],int n);
void insertionSort(int a[],int n);

void shellSort(int a[],int n);

void quickSort(int a[],int n);
void quickSortUtil(int a[],int low,int high);
int partition(int a[],int start,int end);

void heapSort(int a[],int n);
void heapify(int a[],int n,int i);


void mergeSort(int a[],int n);
void mergeSortUtil(int a[],int l,int r);
void merge(int a[],int l,int m,int r);

void println(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<'\n';
    
}
int main(void){
    
    int a[]={2,0,1,5,3,4};
    int n=sizeof(a)/sizeof(a[0]);
    
    //bubbleSort(a,n);
    //selectionSort(a,n);
    //insertionSort(a,n);
    //quickSort(a,n);
    //mergeSort(a,n);
    // heapSort(a,n);
    shellSort(a,n);
    println(a,n);
    
    
}
void shellSort(int arr[],int n){
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}

void bubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=i;j<n-i-1;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
}

void selectionSort(int a[],int n){
    int min_idx;
    for(int i=0;i<n;i++){
        min_idx=i;
        
        for(int j=i+1;j<n;j++)
            if(a[j] < a[min_idx])
                min_idx=j;
        swap(a[i],a[min_idx]);    
    }
}

void insertionSort(int a[],int n){
    int key,j;
    for(int i=1;i<n-1;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        
        a[j+1]=key;
    }
}

void quickSort(int a[],int n){
    quickSortUtil(a,0,n-1);
}

void quickSortUtil(int a[],int s,int e){
    if(s<e){
        int pi=partition(a,s,e);
        quickSortUtil(a,s,pi-1);
        quickSortUtil(a,pi+1,e);
    }
}

int partition(int a[],int s,int e){
    int pivot=a[e];
    int i=s-1;
    
    for(int j=s;j<e;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    
    swap(a[i+1],a[e]);
    return i+1;
}

void mergeSort(int a[],int n){
    mergeSortUtil(a,0,n-1);
}

void mergeSortUtil(int a[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSortUtil(a,l,m);
        mergeSortUtil(a,m+1,r);
        merge(a,l,m,r);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}