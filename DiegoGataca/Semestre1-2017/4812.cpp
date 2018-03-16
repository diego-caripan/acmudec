#include <bits/stdc++.h>

using namespace std;

vector <pair <long long int,long long int> > act;
long long int n,m,a,b,sol;
vector < vector <int> > tabla;

int dp(int ant,int actual){
	if(act[actual].second == n)return 1;
	if(tabla[ant][actual] == -1){
		tabla[ant][actual] = 0;
		for(int j = actual+1; j < m; j++){
			if(act[j].first > act[actual].first && act[j].first <= act[actual].second && act[j].second > act[actual].second && (ant == actual || act[j].first > act[ant].second) ){
				tabla[ant][actual]+=dp(actual,j);
				tabla[ant][actual]%=100000000;							
			}
		}
	}
	return tabla[ant][actual];
}

int main(){	
	while(1){
		scanf("%lld %lld",&n,&m);
		if(n == 0 && m == 0)break;
		act.clear();
		sol = 0;
		for(int i = 0; i < tabla.size();i++){
			tabla[i].clear();
		}
		tabla.resize(m);
		for(int i = 0; i < m; i++){
			scanf("%lld %lld",&a,&b);
			act.push_back(make_pair(a,b));
			tabla[i].resize(m,-1);
		}
		sort(act.begin(),act.end());
		for(int i = 0; i < m; i++){
			if(act[i].first == 0){
				sol += dp(i,i);
				sol %=100000000;	
			}
		}
		printf("%lld\n",sol);
	}
	return 0;
}