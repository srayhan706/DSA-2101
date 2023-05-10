#include <bits/stdc++.h>
using namespace std;

int binsearch(int nums[],int l,int h )
{
	if(nums[0]<nums[h])
        return nums[0];

    int ans=0;
    while(l<h)
    {
        int mid=l+(h-l)/2;
        if(nums[mid]>=nums[0])
        {
            l=mid+1;
            ans=l;
        }
        else
        {
            h=mid;
            ans=h;
        }
    }
    return  nums[ans];


    }



int main(){
    freopen("bin1in.txt","r",stdin);
    freopen("bin1out.txt","w",stdout);
	int n;
	cin>>n;
	int nums[n];
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	int x=binsearch(nums,0,n-1);
	cout<<x;

	return 0;
}
