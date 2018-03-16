#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin>>n) {
		vector <int> hola;
		for (int i = 0; i < n; i++) {
			int lol;
			cin>>lol;
			hola.push_back(lol);
		}
		sort(hola.begin(),hola.end());
		int sum;
		cin>>sum;
		int aux1,aux2;
		int i=0, j=hola.size()-1;
		while(i<j){
			if(hola[i]+hola[j]<sum) i++;
			else if(hola[i]+hola[j]==sum){
				aux1 = i;
				aux2=j;
				i++;
				j--;
			}
			else j--;
		}
		cout<<"Peter should buy books whose prices are "<<hola[aux1]<<" and "<<hola[aux2]<<"."<<"\n"<<"\n";
	}

	return 0;
}