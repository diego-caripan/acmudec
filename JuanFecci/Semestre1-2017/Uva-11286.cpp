#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << endl

int main(){
	int n, aux1, max, auxmax;
	scanf("%d", &n);

	map<vector <int> , int> ma;
	vector <int> aux;
	while (n!=0){
		REP(i,0,n){
			REP(j,0,5){
				scanf("%d", &aux1);
				aux.push_back(aux1);
			}
			sort(aux.begin(), aux.end());
			ma[aux]++;
			aux.clear();
		}

		max = 0;
		auxmax = 0;
		for (map<vector<int> , int>::iterator nico=ma.begin(); nico != ma.end(); nico++){
			if (max < nico->second){
				max = nico->second;
				auxmax = nico->second;
			}
			else if (max == nico->second){
				auxmax += max;
			}
		}

		cout << auxmax << endl;

		aux.clear();
		ma.clear();
		scanf("%d", &n);
	}
}