#include <bits/stdc++.h>
using namespace std;

int main(){
	map<int,int> mapa;
	int Re,Ni,num,ans,ct,bl;
	cin>>Re;
	while(Re--){
		mapa.clear();
		cin>>Ni;
		ans=0,ct=0,bl=0;
		for(int i=1;i<=Ni;++i){
			cin>>num;
			int aux=mapa[num];
			if(aux!=0){
				bl=max(bl,aux);
				ct=i-bl-1;
			}
			ct++;
			mapa[num]=i;
			ans=max(ans,ct);
		}
		cout<<ans<<endl;
	}
}