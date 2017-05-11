// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;
 
// Prototype of a utility function to swap two integers
void swap(int *x, int *y);
 
class Heap{
 
    public:
    int parent(int i) { return (i-1)/2; }
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
    
};
 
// A class for Max Heap
class MaxHeap : public Heap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MaxHeap(int capacity);
 
    // to heapify a subtree with root at given index
    void MaxHeapify(int );
 
    // to extract the root which is the maximum element
    int extractMax();
 
    // Increases key value of key at index i to new_val
    void increaseKey(int i, int new_val);
 
    // Returns the maximum key (key at root) from min heap
    int getMax() { return harr[0]; }
 
    // Deletes a key stored at index i
    void deleteKey(int i);
 
    // Inserts a new key 'k'
    void insertKey(int k);
    
    //resize
    void resize();
};

//resize heap
void MaxHeap::resize(){
    int *arr_old=harr;
    harr=new int[capacity*2];
    
    for(int i=0;i<heap_size;i++)
        harr[i]=arr_old[i];
    capacity*=2;
    delete arr_old;
}
 
// Constructor: Builds a heap from a given array a[] of given size
MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
 
// Inserts a new key 'k'
void MaxHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        resize();
    }
 
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
 
    // Fix the max heap property if it is violated
    while (i != 0 && harr[parent(i)] < harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Increases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MaxHeap::increaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] < harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MaxHeapify(0);
 
    return root;
}
 
 
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MaxHeap::deleteKey(int i)
{
    if(i>capacity)
        return;
    increaseKey(i, INT_MAX);
    extractMax();
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && harr[l] > harr[i])
        largest = l;
    if (r < heap_size && harr[r] > harr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&harr[i], &harr[largest]);
        MaxHeapify(largest);
    }
}
 
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
 
 
// A class for Min Heap
class MinHeap : public Heap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);
 
    // to heapify a subtree with root at given index
    void MinHeapify(int );
 
    // to extract the root which is the minimum element
    int extractMin();
 
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
 
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }
 
    // Deletes a key stored at index i
    void deleteKey(int i);
 
    // Inserts a new key 'k'
    void insertKey(int k);
    
    void resize();
};
 
 void MinHeap::resize(){
     int *arr_old=harr;
     harr=new int[capacity*2];
     
     for(int i=0;i<heap_size;i++)
        harr[i]=arr_old[i];
        
    capacity*=2;    
    delete arr_old;
 }
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
 
// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        resize();
    }
 
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
 
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
 
    return root;
}
 
 
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
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

void buildHeap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
}

void heapSort(int arr[],int n){
    
    buildHeap(arr,n);
    
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    
}
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int KthLargest(int arr[],int n,int k){
    MaxHeap h(n);
    for(int i=0;i<n;i++)
        h.insertKey(arr[i]);
    int el=0;
    while(k--)
        el=h.extractMax();
        
    return el;
}
// Driver program to test above functions
int main()
{
    MaxHeap h(4);
    h.insertKey(300);
    h.insertKey(2);
    h.deleteKey(100);
    h.insertKey(1500);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMax() << " ";
    cout << h.getMax() << " ";
    h.increaseKey(2, 1);
    cout << h.getMax()<<endl;
    
    
    MinHeap h2(1);
    h2.insertKey(3);
    h2.insertKey(2);
    h2.deleteKey(1);
    h2.insertKey(15);
    h2.insertKey(5);
    h2.insertKey(4);
    h2.insertKey(45);
    cout << h2.extractMin() << " ";
    cout << h2.getMin() << " ";
    h2.decreaseKey(2, 1);
    cout << h2.getMin();
    
    
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "\nSorted array is \n";
    printArray(arr, n);
    
    int k=3;
    cout<< "\nKth Largest is : "<<KthLargest(arr,n,k);
    
    return 0;
}