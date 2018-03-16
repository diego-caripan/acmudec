/*
	CODIGO PROPIO

*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	while(cin>>t&&t){
		vector<pair<string,char> > v;
		string a1;
		char a2;
		for(int i=0;i<t;i++){
			cin>>a1>>a2;
			v.push_back(make_pair(a1,a2));
		}
		sort(v.begin(),v.end());
		int entradas,cur,maxi;
		entradas=cur=maxi=0;
		for(int i=0;i<t;i++){
			if(v[i].second=='E'){
				entradas++;
			}
		}
		for(int i=0;i<t;i++){
			if(v[i].second=='E'){
				cur++;
				maxi=max(cur,maxi);
			}else if(v[i].second=='X'){
				cur--;
			}else if(v[i].second=='?'){
				if(entradas<t/2){
					entradas++;
					cur++;
					maxi=max(cur,maxi);
				}else{
					cur--;
				}
			}
		}
		cout<<maxi<<endl;
	}
	return 0;
}