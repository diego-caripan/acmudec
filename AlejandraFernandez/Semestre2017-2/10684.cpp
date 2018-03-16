#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	while (n) {
		vector <int> hola;
		int aux = 0;
		int max = -10000;
		for (int i = 0; i < n; i++) {
			int lol;
			cin>>lol;
			hola.push_back(lol);
		}
		for(int i=0;i<n;i++){
			aux += hola[i];
			if(aux>max) max = aux;
			if (aux<0) aux = 0;
		}
		if (max > 0) cout<<"The maximum winning streak is "<<max<<"."<<"\n";
		else cout<<"Losing streak.\n";
		cin>>n;
	}

	return 0;
}