#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <cctype>
#include <cstring>

using namespace std;

map<int, int> fibIdx, revFibIdx;

//En esta funcion se asocia a cada valor fibonacci la posicion que le corresponde, almacenada en revFibIdx.
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

//Esta funcion inicializa los valores fibonacci.
void init() {

	fibIdx[1] = 1;
	fibIdx[2] = 2;
	revFibIdx[1] = 1;
	revFibIdx[2] = 2;
	fib(46);
}

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
			cout << key[i] << endl;
				//Almacena los valores de Fibonacci ingresados y obtiene el maximo.
				if (key[i] > max){
					max = key[i];
					cout << "max: " << max << endl;
				}
		}

		i = 0;
	
		scanf("%c", &c);

		while (true) {
			
			scanf("%c", &c);
			
			if (c == '\n')
				break;
			//Se lee la frase caracter por caracter hasta el salto de linea y se verifica que sean mayusculas 
			//y solo letras por medio de isupper().
			if (isupper(c))
				s[i++] = c;
		}

		//revFibIdx almacena la posicion en la cual debe ir cada caracter de acuerdo a los numeros fibonacci 
		//ingresados.
		for (i = 0; i < revFibIdx[max]; i++) {
			//Se inicualiza todo el arreglo ans con espacios en blanco, dado que si se salta algun numero
			//fibonacci, esto representa que es un espacio.
			ans[i] = ' ';
		}
		//Por medio de este for se obtiene el valor asociado a cada letra, con el cual se mapea en revFibIdx
		//para asi obtener la posicion en el arreglo ans, el cual almacena la palabra ya decodificada.
		for (i = 0; i < n; i++) {
			ans[revFibIdx[key[i]] - 1] = s[i];
		}

		ans[revFibIdx[max]] = '\0';
		printf("%s\n", ans);
	}	

	return 0;
}
