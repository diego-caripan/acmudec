#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,m;
	while(scanf("%d",&n)!=EOF){
		vector <int> v,ve;
		bool b=true;
		for(int i=0;i<n;i++){
			cin>>m;
			v.push_back(m);
		}
		for(int i=0;i<n-1;i++){
			int j=abs(v[i]-v[i+1]);
			ve.push_back(j);
		}
		sort(ve.begin(),ve.end());
		for(int i=0;i<n-1;i++){
			if(ve[i]!=i+1) b=false;
		}
		if(b || n == 1) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
	}