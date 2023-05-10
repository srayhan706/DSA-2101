#include <bits/stdc++.h>
using namespace std;

int binsearch(int nums[],int l,int h,int target)
{

      while(l<=h){
      int mid = l+(h-l)/ 2;
        if(nums[mid] == target)
         return mid;
        if(nums[mid] >= nums[l]) {
          if(target >= nums[l] && target <= nums[mid])
            {
                h = mid - 1;
            }
           else l = mid + 1;
        }
        else {
          if(target >= nums[mid] && target <= nums[h])
            l = mid + 1;
          else h= mid - 1;
        }
          mid = l + (h- l) / 2;

   }
   return -1;
}



int main(){
    freopen("bin2in.txt","r",stdin);
    freopen("bin2out.txt","w",stdout);
	int n;
	cin>>n;
	int nums[n];
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	int t;
	cin>>t;
	int in=binsearch(nums,0,n-1,t);
	cout<<in;
}
