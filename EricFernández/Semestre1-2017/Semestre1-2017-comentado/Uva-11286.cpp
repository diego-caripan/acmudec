#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n, A[5];
	//un arreglo que sirve como buffer
	char buf[20];
	while(scanf("%d", &n) == 1 && n) {
		string str;
		map<string, int> record;
		while(n--) {
			//lee la entrada
			scanf("%d %d %d %d %d", &A[0], &A[1], &A[2], &A[3], &A[4]);
			//ordena la entrada
			sort(A, A+5);
			//añade lso elementos ordenados al buffer
			sprintf(buf, "%d%d%d%d%d", A[0], A[1], A[2], A[3], A[4]);
			//añade al mapa
			str = buf;
			record[str]++;
		}
		int max = 0, maxNum = 0;
		//recorre el mapa
		for(map<string, int>::iterator i = record.begin(); i != record.end(); i++) {
			// si el valor del mapa es mayor a max entonces max toma el valor del mapa
			if(i->second > max)
				max = i->second, maxNum = 0;
			//si son iguales entocnes el numero maximo sera el numero maximo mas el maximo calculado
			if(i->second == max)
				maxNum += max;
		}
		//imprime el numero maximo de estudiantes que toman la combinacion mas popular
		printf("%d\n", maxNum);
	}
    return 0;
}