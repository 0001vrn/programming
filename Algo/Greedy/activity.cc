/*

Activity Selection Program

You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time.

*/

#include<bits/stdc++.h>
using namespace std;
void printMaxActivities(int s[],int f[],int n){
    
    int i, j;
 
    printf ("\nFollowing activities are selected \n");
 
    // The first activity always gets selected
    i = 0;
    printf("%d ", i);
 
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= f[i])
      {
          printf ("%d ", j);
          i = j;
      }
    }
    
}


struct Activity{
  int start, finish;
};

bool compare(Activity s1, Activity s2){
    return s1.finish < s2.finish;
}

void printMaxActivities(Activity arr[], int n){
    
    sort(arr, arr+n, compare);

    int i, j;
 
    printf ("\nFollowing activities are selected \n");
 
    // The first activity always gets selected
    i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (arr[j].start >= arr[i].finish)
      {
        cout << "(" << arr[j].start << ", "
              << arr[j].finish << "), ";
          i = j;
      }
    }
    
}

/* Time Complexity

    O(nlogn) time if input activities are not sorted.
    O(n) time if input activites are sorted.

*/
int main(void){
    
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    n = sizeof(arr)/sizeof(arr[0]);
    printMaxActivities(arr, n);
    return 0;
}