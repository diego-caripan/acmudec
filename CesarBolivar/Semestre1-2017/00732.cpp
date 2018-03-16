// César Bolívar Severino
// Solución sacada de
// https://github.com/morris821028/UVa/blob/master/volume007/732%20-%20Anagrams%20by%20Stack.cpp

#include <stdio.h>
#include <string.h>

char a[105];// la palabra original
char b[105];// la palabra que se desea porducir usando un stack y la palabra
			// original
char buf[105];
// el stack
char stk[105];
char w[105];
// el largo de la palabra original
int len;
int stkIdx;

// Esta función desciende recursivamente por todas las combinaciones de i y o
// válidas. A diferencia de mi implementación (cuyo veredicto fue TLE), la
// palabra resultante se va verificando al mismo tiempo que se recorren todas las
// posibles secuencias de i y o.
void dfs(int idx, int i, int o)
{
	// Si se llega a este punto es porque todos los caracteres de la primera
	// palabra fueron pusheados y popeados del stack, es decir se encontro una
	// secuencia de i y o que genera la segunda palabra. La imprimimos
	if (i == len && o == len) {
		for (int j = 0; j < idx; j++) {
			if (j) {
				putchar(' ');
			}
			putchar(w[j]);
		}
		puts("");
		return;
	}
	// mientras aun se pueda pushear al stack, pusheamos una i y llamamos
	// recursivamente
	if (i < len) {
		stk[stkIdx++] = a[i];
		w[idx] = 'i';
		dfs(idx+1, i+1, o);
		// luego de la llamada recursiva, popeamos del stack
		stkIdx--;
	}
	// si podemos hacer pop, lo hacemos...
	if (i > o) {
		// ...pero solo si el tope del stack coincide con la o-ésima letra de la
		// segunda palabra. Popeamos y llamamos recursivamente
		if (stk[stkIdx-1] == b[o]) {
			w[idx] = 'o';
			stkIdx--;
			dfs(idx+1, i, o+1);
			// luego de la llamada recursiva, dejamos el stack como estaba
			stkIdx++;
			stk[stkIdx-1] = b[o];
		}
	}
}
int main()
{
	while (gets(a)) {
		gets(b);
		puts("[");
		len = strlen(a), stkIdx = 0;
		// Si las 2 palabras difieren en largo es imposible que podamos generar
		// la segunda a partir de la primera, asi que ni si quiera nos molestamos en
		// intentarlo
		if (strlen(a) == strlen(b)) {
			dfs(0, 0, 0);
		}
		puts("]");
	}
	return 0;
}
