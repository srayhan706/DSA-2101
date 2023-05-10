#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	queue<int> q;

	int pre[n][2];
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>pre[i][j];
		}
	}

	int indg[n];
	std::vector<int> res;
	for(int i=0;i<n;i++){
		indg[i]=0;
	}

	int adjlist[n][n];
	for(int i=0;i<n;i++){
		int u=pre[i][0];
		int v=pre[i][1];
		adjlist[v][indg[u]++]=u;
	}

	for (int i = 0; i < n; i++) {
            if (indg[i] == 0) {
                q.push(i);
            }
        }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int v : adjlist[u]) {
            indg[v]--;
            if (indg[v] == 0) {
                q.push(v);
            }
        }
    }
	
	
}