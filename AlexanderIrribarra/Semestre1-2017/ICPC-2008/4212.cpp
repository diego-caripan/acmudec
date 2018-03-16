/*
	codigo propio
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll solve(vector<ll> &a){
	ll x=0,y=0;
	for(int i=0;i<a.size();i++){
		ll aux=x;
		x=max(x,a[i]+y);
		y=aux;
		//cout<<"a: "<<x<<endl;
		//cout<<"b: "<<y<<endl;
	}
	//cout<<endl;acz
	return x;
}

int main(){
	int n,m;
	while(cin>>n>>m && n && m){
		vector<ll> r(n);
		for(int i=0;i<n;i++){
			vector<ll> a(m);
			for(int j=0;j<m;j++){
				ll aux;
				cin>>aux;
				a[j]=aux;
			}
			r[i]=solve(a);
		}
		cout<<solve(r)<<endl;
	}
	return 0;
}
