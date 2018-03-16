/*
	CODIGO PROPIO

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
	ll n;
	ll x[1000];
	ll y[1000];
	ll r[1000009];
	while(cin>>n && n){
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i];
		}
		ll total=0;
		for(ll i=0;i<n;i++){
			ll ind=0;
			for(ll j=0;j<n;j++){
				if(i!=j){
					ll d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
					r[ind++]=d;
				}
			}
			sort(r,r+ind);
			ll c=0;
			ll k=0;
			ll val=-1;
			while(k<ind){
				if(r[k]!=val){
					val=r[k];
					total+=c*(c-1)/2;
					c=1;
					k++;
				}else{
					c++;
					k++;
				}
			}
			total+=c*(c-1)/2;
		}
		cout<<total<<endl;
	}
	return 0;
}