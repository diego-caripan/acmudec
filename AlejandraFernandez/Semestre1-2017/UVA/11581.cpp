//codigo comentado 
// Fuente : https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%2011581%20-%20Grid%20Successors/src/UVa%2011581%20-%20Grid%20Successors.cpp
#include <cstdio>
using namespace std;

int g[3][3];

void f() {									//algoritmo que va iterando las reglas del ejercicio
	int h[3][3];

	h[0][0] = (g[0][1] + g[1][0]) % 2;
	h[0][1] = (g[0][0] + g[1][1] + g[0][2]) % 2;
	h[0][2] = (g[0][1] + g[1][2]) % 2;

	h[1][0] = (g[0][0] + g[1][1] + g[2][0]) % 2;
	h[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1]) % 2;
	h[1][2] = (g[1][1] + g[0][2] + g[2][2]) % 2;

	h[2][0] = (g[2][1] + g[1][0]) % 2;
	h[2][1] = (g[2][0] + g[1][1] + g[2][2]) % 2;
	h[2][2] = (g[2][1] + g[1][2]) % 2;

	for (int i = 0; i < 3; i++) {			//luego la matriz original se iguala a la matriz con modificaciones
		for (int j = 0; j < 3; j++) {
			g[i][j] = h[i][j];
		}
	}
}

bool isZero() {								//funcion que envia true si la matriz contiene puros 0, y false en otro caso
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g[i][j] > 0)
				return false;
		}
	}
	return true;
}

int main() {
	int TC;

	scanf("%d", &TC);

	while (TC--) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%1d", &g[i][j]);		// se llena la matriz
			}
		}

		int ans = -1;
		while (!isZero()) {		// En esta funcion si la matriz no esta llena de 0 se hace la modificacion con las reglas
			f();				//y cada vez que se modifica la matriz se vuelve a ver si esta llena de 0 o no
			ans++;				// cada vez que la matriz se modifica se agrega uno a la respuesta
		}

		printf("%d\n", ans);
	}

	return 0;
}