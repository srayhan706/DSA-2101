#include <bits/stdc++.h>
using namespace std;

class Minheap{

public:
	int *harr;
	int cap;
	int size;

public:
	Minheap(int c){
		size=0;
		cap=c;
		harr=new int[c];
	}


	int parent(int i){
		return (i-1)/2;
	}
	int left(int i){
		return (2*i)+1;
	}
	int right(int i){
		return (2*i)+2;
	}

	void Minheapify(int i){
		int l=left(i);
		int r=right(i);
		int small=i;
		if(l<size && harr[l]<harr[i]){
			small=l;
		}
		if(r<size && harr[r]<harr[small]){
			small=r;
		}
		if(small!=1){
			swap(&harr[i],&harr[small]);
			Minheapify(small);
		}
	}


	int extracMin(){
	    if (size <= 0)
	        return INT_MAX;
	    if (size == 1)
	    {
	        size--;
	        return harr[0];
	    }
	 
	    // Store the minimum value, and remove it from heap
	    int root = harr[0];
	    harr[0] = harr[size-1];
	    size--;
	    Minheapify(0);
	 
	    return root;
	}

	void decreasekey(int i,int n){
		harr[i]=n;
		while(i!=0 && harr[parent(i)]>harr[i]){
			swap(&harr[i],&harr[parent(i)]);
			i=parent(i);
		}
	}

	int getmin(){
		return harr[0];
	}

	void deltekey(int i){
		decreasekey(i,INT_MIN);
		extracMin();
	}

	void insert(int k){
		if (size == cap)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
 
    // First insert the new key at the end
	   	size++;
	    int i = size - 1;
	    harr[i] = k;
	 
	    // Fix the min heap property if it is violated
	    while (i != 0 && harr[parent(i)] > harr[i])
	    {
	       swap(&harr[i], &harr[parent(i)]);
	       i = parent(i);
	    }
	}

	void swap(int *x, int *y){
		int temp = *x;
		*x = *y;
		*y = temp;
	}
	void display(){
		for(int i=0;i<size;i++){
			cout<<harr[i]<<" ";
		}
		cout<<endl;
	}

};



int main(){
	Minheap h(10);
	h.insert(3);
	h.insert(2);
	h.insert(1);
	h.insert(15);
	h.insert(5);

	cout<<h.getmin()<<endl;
	h.display();
	h.deltekey(15);
	h.display();
}