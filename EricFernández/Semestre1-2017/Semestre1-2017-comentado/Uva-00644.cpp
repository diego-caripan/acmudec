//lo robe de la carpeta de al lado
#include <bits/stdc++.h>
using namespace std;
//ahorrar el for(...)
#define REP(i,a,b) for(int i=a; i< b; i++)
//no la usa
void D(int x, string fin="\n"){
	cout << x << fin;
}

int main(){
	int ind=1;
	bool verif;//para ver que cosa imprmir
	string n, aux;
	vector <string> palabras;
	//lee la cantidad de casos
	while(cin >> n){
		//lee la entrada
		while(n != "9"){
			palabras.push_back(n);
			cin >> n;
		}
		//inicializa en false 
		verif = false;
		//revisa si un sub string es prefijo de otro
		//si lo es, entonces termine el while porque no es decodificable
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
		//imprime de acuerdo al valor de verif
		if (verif==false) cout << "Set " << ind++ << " is immediately decodable\n";
		else cout << "Set " << ind++ << " is not immediately decodable\n";
		//limpia el vector para una nueva entrada
		palabras.clear();

	}
}