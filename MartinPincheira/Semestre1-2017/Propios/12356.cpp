#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){

	int derecha[100000];
	int izquierda[100000];

	int s, b, izq, der, aux1, aux2;
	

	while(cin >> s >> b){

		if(s==0 && b==0) break;

		for(int i=1; i<=s; i++){

			derecha[i] = i+1;
			izquierda[i] = i-1;
		}
	
		while(b){

			cin >> izq;
			cin >> der;

			if(izquierda[izq] >= 1){ 
				cout << izquierda[izq] << " ";
			}

			else 
				cout << "* ";

			if (derecha[der] <= s){ 
				cout << derecha[der] << endl;
			}

			else 
				cout << "*" << endl;

			aux1 = izquierda[izq];
			aux2 = derecha[der];

			derecha[aux1] = derecha[der];
			izquierda[aux2] = izquierda[izq];

			b--;
		}

		cout << "-" << endl;
	}

	return 0;
}
