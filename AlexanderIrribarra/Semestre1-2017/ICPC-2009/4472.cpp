/*
	CODIGO PROPIO

*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
int n,t;

int dfs(int node){
	if(g[node].size()==0){
		return 1;
	}
	int s=g[node].size();
	vector<int> leaves;
	for(int i=0;i<s;i++){
		leaves.push_back(dfs(g[node][i]));
	}
	int res=0;
	sort(leaves.begin(),leaves.end());
	for(int i=0;i<(int)ceil(s*t/100.0);i++){
		res+=leaves[i];
	}
	return res;
}

int main(){
	while(cin>>n>>t && n+t){
		g.assign(n+1,vector<int>());
		for(int i=1;i<=n;i++){
			int aux;
			cin>>aux;
			g[aux].push_back(i);
		}
		cout<<dfs(0)<<endl;
	}
	return 0;
}