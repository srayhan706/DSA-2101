#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("matin.txt","r",stdin);
    freopen("matout.txt","w",stdout);
	int m,n;
	cin>>m;
	cin>>n;
	int mat[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
			}
	}
	//std::vector<int> v;
	vector<int> k;
        for (int r=0; r<m; r++)        // r-> row
        {
            k.clear();
            for (int j=0,i=r; j<n && i<m ; j++,i++) k.push_back(mat[i][j]);
            sort(k.begin(),k.end());
            for (int j=0,i=r; j<n && i<m ; j++,i++) mat[i][j]=k[j];
        }
        for (int c=1; c<n; c++)
        {
            k.clear();
            for (int i=0, j=c; j<n && i<m; i++, j++) k.push_back(mat[i][j]);
            sort(k.begin(),k.end());
            for (int i=0, j=c; j<n && i<m; i++, j++) mat[i][j] = k[i];
        }
    for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
			}
			cout<<endl;
	}


}
