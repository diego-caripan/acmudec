#include <cstdio>

using namespace std;

int g[3][3];

/*Esta funcion se encarga de aplicar las transformaciones correspondientes, la cual usa una matriz auxiliar para guardar los
nuevos valores y luego copiarlos a la matriz original g.
Para ello toma los valores adyacentes de cada posicion del arreglo, los suma y les aplica modulo 2, para asi obtener 1 o 0*/
void f() {
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

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			g[i][j] = h[i][j];
		}
	}
}

//esta funcion se encarga de verificar que la matriz g, luego de aplicar las transformaciones este solo compuesta de 0's,
//para lo cual retornara verdadero en caso de ser asi, o falso en el caso contrario.
bool isZero() {

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

		//Se almacena en la matriz g los valores 0's y 1's ingresados.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%1d", &g[i][j]);
			}
		}
		
		//Se inicializa en -1 si es que no se realiza ninguna transformacion, el cual es el caso de que toda la
		//matriz sea 0.
		int ans = -1;
	
		//Se verifica que la matriz este llena de 0's, si no es asi se aplica la funcion f y se aumenta en uno
		//el contador que lleva el numero de transformaciones.
		while (!isZero()) {
			f();
			ans++;
		}
		
		printf("%d\n", ans);
	}

	return 0;
}
