#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i,j,x,cont;
	vector<int> aux;
	map<vector<int>,int> m;
	while(cin >> n){
		if(n == 0)
			break;
		for(i=0 ; i<n ; i++){
			for(j=0 ; j<5 ; j++){
				cin >> x;
				aux.push_back(x);
			}
			sort(aux.begin(),aux.end());
			m[aux]++;
			aux.clear();
		}
		map<vector<int>,int>::iterator it;
		cont = 0;
		x = 0;
		for(it=m.begin() ; it!=m.end() ; it++){
			if(it->second == x && cont > 0)
				cont += it->second;
			else if(it->second > x || cont == 0){
				cont = it->second;
				x = it->second;
			}
		}
		cout << cont << endl;
		m.clear();
	}
	return 0;
}