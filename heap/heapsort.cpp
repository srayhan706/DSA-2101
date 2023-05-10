#include <bits/stdc++.h>
using namespace std;

void hpify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
      hpify(arr, n, largest);
    }
  }

void hsort(int arr[],int n){

	for(int i=n/2-1;i>=0;i--){
		hpify(arr,n,i);
	}

	for(int i=n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		hpify(arr,i,0);
	}

}

void printarr(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	printarr(arr,n);
	hsort(arr,n);
	cout<<"Sorted array after applying heap sort"<<endl;
	printarr(arr,n);
}