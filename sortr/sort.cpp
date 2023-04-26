#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void fillarr(int arr[],int n)
{
  int lb=9999,ub=100000;
  for(int i=0;i<n;i++){
      arr[i]=(rand()%(ub-lb+1))+lb;
  }
}

int  findmax(int arr[],int n)
{
  int x=arr[0];
  for(int i=0;i<n;i++){
      if(x<arr[i]){
          x=arr[i];
      }
  }
  return x;
}
void swap(int *a,int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}
int  partition(int arr[],int low,int high,int place)
{
  int pivot=(arr[high]/place)%10;
  int i=low-1;
  for(int j=low;j<high;j++){
      if((arr[j]/place)%10<=pivot){
          i++;
          swap(&arr[j],&arr[i]);
      }
  }
  swap(&arr[i+1],&arr[high]);
  return i+1;
}
void quicksort(int arr[],int low,int high,int place)
{
  if(low<high){
      int pi=partition(arr,low,high,place);
      quicksort(arr,low,pi-1,place);
      quicksort(arr,pi+1,high,place);
  }
}
void merge(int a[], int l, int m, int r,int p)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if ((L[i]/p)%10 <= (R[j]/p)%10) {
           a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r,int p)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(a, l, m,p);
        mergeSort(a, m + 1, r,p);

        merge(a, l, m, r,p);
    }
}

int main()
{
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      int n;
      cin>>n;
      int arr[n];
      
      fillarr(arr,n);
      int max=findmax(arr,n);

      auto start1 = high_resolution_clock::now();
      for(int place=1;(max/place)>0;place=place*10){
      quicksort(arr,0,n-1,place);
      }
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }
      cout<<endl;

      auto stop1 = high_resolution_clock::now();
      auto duration1 = duration_cast<microseconds>(stop1 - start1);
      cout << "Time taken by quick: "
             << duration1.count() << " microseconds" << endl;

      cout<<endl;

      auto start2 = high_resolution_clock::now();
      for(int place=1;(max/place)>0;place=place*10){
        mergeSort(arr,0,n,place);
      }
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }
      cout<<endl;

      auto stop2 = high_resolution_clock::now();
      auto duration2 = duration_cast<microseconds>(stop2 - start2);
      cout << "Time taken by merge: "
             << duration2.count() << " microseconds" << endl;

      cout<<endl;
}
