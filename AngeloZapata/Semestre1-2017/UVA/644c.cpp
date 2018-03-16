//https://github.com/dseco/acmudec/blob/master/JuanFecci/Semestre1-2017/Uva-644.cpp
#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)

void D(int x, string fin="\n"){
	cout << x << fin;
}

int main(){
	int ind=1;		//es el numero de set.
	bool verif;
	string n, aux;
	vector <string> palabras;
	while(cin >> n){
		while(n != "9"){		//lee un set.
			palabras.push_back(n);
			cin >> n;
		}
		verif = false;
		for (int i=0; i<palabras.size(); i++){			//verifica si uno es prefijo de otra.
			for (int j=0; j<palabras.size(); j++){
				if (j!=i && palabras[i].size() > palabras[j].size()){
					aux = palabras[i].substr(0,palabras[j].size());
					if (aux == palabras[j]){		//en caso de ser prefijo.
						verif = true;
						break;
					}
				}
			}
			if (verif){
				break;
			}
		}

		if (verif==false) cout << "Set " << ind++ << " is immediately decodable\n"; //si no hay prefijo.
		else cout << "Set " << ind++ << " is not immediately decodable\n";			//si hay prefijo.

		palabras.clear();		//se limpia el vector.

	}
}