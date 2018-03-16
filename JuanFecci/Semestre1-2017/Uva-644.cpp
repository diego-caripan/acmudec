#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)

void D(int x, string fin="\n"){
	cout << x << fin;
}

int main(){
	int ind=1;
	bool verif;
	string n, aux;
	vector <string> palabras;
	while(cin >> n){
		while(n != "9"){
			palabras.push_back(n);
			cin >> n;
		}
		verif = false;
		for (int i=0; i<palabras.size(); i++){
			for (int j=0; j<palabras.size(); j++){
				if (j!=i && palabras[i].size() > palabras[j].size()){
					aux = palabras[i].substr(0,palabras[j].size());
					if (aux == palabras[j]){
						verif = true;
						break;
					}
				}
			}
			if (verif){
				break;
			}
		}

		if (verif==false) cout << "Set " << ind++ << " is immediately decodable\n";
		else cout << "Set " << ind++ << " is not immediately decodable\n";

		palabras.clear();

	}
}