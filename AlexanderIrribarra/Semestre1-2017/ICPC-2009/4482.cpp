/*
	CODIGO PROPIO

*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin>>n && n){
		vector<vector<int> > v(n,vector<int>(1001,0));
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			for(int j=0;j<k;j++){
				int aux;
				cin>>aux;
				v[i][aux]++;
			}
			for(int j=1;j<1001;j++){
				v[i][j]+=v[i][j-1];
			}
		}
		unsigned long long mini=1000000009;
		for(int i=0;i<1001;i++){
			unsigned long long sum=0;
			for(int j=0;j<n;j++){
				sum+=abs(2*v[j][i]-v[j][1000]);
			}
			mini=min(mini,sum);
		}
		cout<<mini<<endl;
	}
	return 0;
}