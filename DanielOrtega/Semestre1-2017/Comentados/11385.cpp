#include <cstdio>
#include <cmath>
#include <map>
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

map<int, int> fibIdx, revFibIdx;


//genera los numeros de fibonacci
/*
en donde 
fibIdx[n] corresponde a los numeros de fibonacci

0 1 2 3 4 5  6  7  8  9  10
1 1 2 3 5 8 13 21  34 55 89
revFibIdx corresponde a los indices correspondientes a lo numeros de fibonacci
osea
0 1 2 3 4 5 6 7 8 9 10 11 12 13
. 1 2 3 . 5 . . 8 . .   .  .  13
*/
int fib(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (fibIdx.count(n) != 0)
		return fibIdx[n];

	int ans = fib(n - 1) + fib(n - 2);
	fibIdx[n] = ans;
	revFibIdx[ans] = n;
	return ans;
}


// se encarga de inicializar el arrelgo que contiene los numeros de fibonacci
void init() {
	fibIdx[1] = 1;
	fibIdx[2] = 2;
	revFibIdx[1] = 1;
	revFibIdx[2] = 2;
	fib(46);
}

/*

La idea general es:
inicializar el arreglo que contiene los numeros de fibonacci,
una vez inicializados, procedo a leer la entrada, con los numeros de fibonacci, donde me preocupo de buscar el elemento mayor
ya que despues, en esa posicion se pondra el \0

luego se reordena el orden de los caracteres en el string siempre que esten dentro del rango de A y Z
*/

int main() {
	int tc, n, i;
	char s[10001], ans[10001], c;
	int key[100];

	init();

	scanf("%d", &tc);
	while (tc--) {


		scanf("%d", &n);
		int max = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &key[i]);
			// buscar el maximo elemento de la secuencia de numeros ingresadas, ya que despues de esta posicion se debe agregar el final de string
			if (key[i] > max)
				max = key[i];
		}

		i = 0;
		scanf("%c", &c);
		while (true) {
			scanf("%c", &c);
			if (c == '\n')
				break;
			if (isupper(c))
				s[i++] = c;
		}


		for (i = 0; i < revFibIdx[max]; i++) {
			ans[i] = ' ';
		}
		// hace busca por el numero en el fibonacci reverso, asi obtiene inmediantamente la solucion y la guarda el caracter que corresponde 
				for (i = 0; i < n; i++) {
					ans[revFibIdx[key[i]] - 1] = s[i];
					
				}]
		ans[revFibIdx[max]] = '\0';

		printf("%s\n", ans);
	}

	return 0;
}