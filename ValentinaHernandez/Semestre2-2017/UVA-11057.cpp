#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> par;
#define pb push_back

int main(){
	int N;
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> N){
		int m;
		vector<int> v;
		for(int i=0 ; i<N ; i++){
			cin >> m;
			v.pb(m);
		}
		cin >> m;
		par p(-1,-1);
		ll sum;
		for(int i=0 ; i<v.size() ; i++){
			for(int j=i+1 ; j<v.size() ; j++){
				par q;
				sum = v[i]+v[j];
				if(sum == m){
					if(p.first == -1 && p.second == -1){
						if(v[i] >= v[j]){
							p.first = v[j];
							p.second = v[i];
						}
						else{
							p.first = v[i];
							p.second = v[j];
						}
					}
					else{
						if(v[i] >= v[j]){
							q.first = v[j];
							q.second = v[i];
						}
						else{
							q.first = v[i];
							q.second = v[j];
						}
						ll r1 = abs(p.first-p.second), r2 = abs(q.first-q.second);
						if(r2 < r1){
							p.first = q.first;
							p.second = q.second;
						}
					}
				}
			}
		}
		cout << "Peter should buy books whose prices are " << p.first << " and "<<p.second<<".\n\n";
		v.clear();
	}
	return 0;
}