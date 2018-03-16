// Sacado de https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%2011742%20-%20Social%20Constraints/src/UVa%2011742%20-%20Social%20Constraints.cpp
#include <cstdio>
#include <algorithm>
using namespace std;

int find(int p, int arr[]) {    //funcion que busca a la persona p en el arreglo arr, devuelve la posicion i donde está sentada la persona p.
	int i;
	for (i = 0; i < 8; i++) {
		if (arr[i] == p)
			break;
	}
	return i;
}

int main() {
	int n, m;
	int constraints[20][3];     //almacena las restricciones a aplicar sobre el grupo de personas

	while (scanf("%d %d", &n, &m) && (n!=0 || m!=0)) {  //mientras uno de los dos valores (m o n) sea distinto de 0, continúa ejecutandose, el bucle termina cuando ambos son igual a 0.
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &constraints[i][0], &constraints[i][1],
					&constraints[i][2]);    //aqui se ingresan los valores de a, b y c respectivamente para cada restricción.
		}

		int arr[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };    // como a lo más pueden ser 8 personas, se tiene este arreglo para a través de next_permutation obtener todas las permutaciones

		int ans = 0;
		do {
			bool flag = true;                        // si es false, significa que no se cumple la restriccion necesaria, si es true entonces es una solución válida
			for (int i = 0; i < m; i++){             // se toma la iteración actual y se le aplican las m restricciones para ver si las cumple, esto se aplica a las n! permutaciones.
				int pos1 = find(constraints[i][0], arr);    //busca la posición de "a" en la permutacion
				int pos2 = find(constraints[i][1], arr);    //busca la posicion de "b" en la permutacion
				if (constraints[i][2] > 0) {                // Ahora si c es positivo...
					if (abs(pos1 - pos2) > constraints[i][2]) { // ... y no cumple que a y b estén a lo más a c posiciones de distancia...
						flag = false;                           // ... entonces la permutación no es solución.
						break;
					}
				}
				if (constraints[i][2] < 0) {                    // Pero si c es negativo...
					if (abs(pos1 - pos2) < (-constraints[i][2])) { // ... y no cumple que a y b estén a lo menos a -c posiciones de distancia...
						flag = false;                              // ... entonces la permutación no es solución.
						break;
					}
				}
			}

			if (flag)       // de cumplirse las condiciones, entonces agregar esta permutación como solución válida
				ans++;
		} while (next_permutation(arr, arr + n));   // obtiene todas las permutaciones del arreglo arr hasta el n-ésimo elemento.

		printf("%d\n", ans);    //finalmente, imprime todas las soluciones, si m = 0 (no hay restricciones), entonces las n! permutaciones son soluciones válidas.
	}

	return 0;
}