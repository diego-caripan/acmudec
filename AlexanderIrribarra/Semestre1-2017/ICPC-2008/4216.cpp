/*
	CODIGO PROPIO
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin>>n && n){
		vector<int> v(n,-1);
		bool work=true;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;	
			if(i+b>=0 && i+b<n && v[i+b]==-1){
				v[i+b]=a;
			}else{
				work=false;
			}
		}
		if(work){
			for(int i=0;i<n-1;i++){
				cout<<v[i]<<" ";
			}
			cout<<v[n-1]<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}