#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
	// esta matriz contiene en cada posicion (i,j) la suma de las submatrices cuya esquina superior izquierda es (0,0) y esquina inferior derecha es (i,j)
	int A[100][100];
	// la dimension de la matriz
	int n;
	scanf("%d", &n);
	// iterador de filas
	for (int i = 0; i < n; i++) {
		// iterador de columnas
		for (int j = 0; j < n; j++) {
			// lee el valor corresondiente a esta posicion
			scanf("%d", &A[i][j]);
			// al valor actual le suma la submatriz que llega hasta la fila anterior (si es que existe)
			if (i > 0) {
				A[i][j] += A[i - 1][j];
			}
			// al valor actual le suma la submatriz que llega hasta la columna anterior (si es que existe)
			if (j > 0) {
				A[i][j] += A[i][j - 1];
			}
			// le resta la submatriz que llega hasta la posicion arriba a la izquierda de la actual (si es que existe), para evitar sumar dos veces sus elementos
			if (i > 0 && j > 0) {
				A[i][j] -= A[i - 1][j - 1];
			}
		}
	}
	// esta variable va a guardar la moyor suma
	int maxSubRect = -127*100*100;
	// itera todas las matrices posibles O(n^4)
	// fila esquina superior izquierda
	for (int i = 0; i < n; i++) {
		// columna esquina superior izquierda
		for (int j = 0; j < n; j++) {
			// fila esquina inferior derecha
			for (int k = i; k < n; k++) {
				// columna esquina inferior derecha
				for (int l = j; l < n; l++) {
					// usando las submatrices previamente calculadas, calcula la suma correspondiente en O(1)
					int subRect = A[k][l];
					// similar a la construccion de la matriz A
					if (i > 0) {
						subRect -= A[i - 1][l];
					}

					if (j > 0) {
						subRect -= A[k][j - 1];
					}

					if (i > 0 && j > 0) {
						subRect += A[i - 1][j - 1];
					}
					// actualiza la suma maxima
					maxSubRect = max(maxSubRect, subRect);
				}
			}
		}
	}
	cout << maxSubRect << endl;
	return 0;
}
