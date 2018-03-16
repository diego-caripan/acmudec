#include <stdio.h>
#include <iostream>
#include <map>

/*Este problema fue resuelto por medio del uso de maps, el cual se ultiliza -en este caso- para asociar caracteres que se pagan con su respectivo valor monetario.

En el primer for solo se almacenan los valores de lo anteriormente descrito.
En el segundo, se lee la linea con el texto correspondiente a analizar por medio de getline, en donde por cada una de ellas recorre el string usando un iterador para encontrar alguna ocurrencia de las letras en el string. Si el iterador no es el final del string, quiere decir que se encontró una de las letras del map, por lo cual añade el valor asociado de la letra al total, y así por cada string que debe ser analizado.
*/
using namespace std;

int main(){

	int T, K, M, l;
	map <char, double> mymap;
	map <char, double>::iterator it;
	char c;
	string line;
	double v, total;

	scanf("%d", &T);
	while(T--){

		total = 0;
		scanf("%d", &K);
	
		for(int i = 0; i < K; i++){
			cin >> c >> v;
			mymap[c] = v;
		}
	
		scanf("%d", &M);
		cin.ignore();
	
		for(int i = 0; i < M; i++){
			line = "";
			getline(cin, line);
			l = line.size();
	
			for(int j = 0; j < l; j++){
				it = mymap.find(line[j]);
				if(it != mymap.end())
				total += it->second;
			}
		}
	
		total /= 100;
		printf("%0.2lf$\n", total);
		mymap.clear();
	}
	
	return 0;
}
