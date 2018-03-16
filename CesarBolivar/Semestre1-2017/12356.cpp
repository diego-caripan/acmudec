// César Bolívar Severino
// Solución sacada de https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%2012356%20-%20Army%20Buddies/src/UVa%2012356%20-%20Army%20Buddies.cpp

#include <cstdio>
using namespace std;

// En lugar de crear un sólo arreglo y desplazar los elementos necesarios cada vez que se lea un par (L,R), lo que hace este programa es tener 2 arreglos: uno con los "buddie" izquierdos de cada persona y otro con los "buddie" derechos. Así se evita el TLE en el casos de que hayan muchos desplazamientos costosos.
int left[100005], right[100005];

int main() {
	int s, b;

	// Se inicializan los 2 arreglos
	while (scanf("%d %d", &s, &b), s || b) {
		for (int i = 1; i <= s; i++) {
			left[i] = i - 1;
			right[i] = i + 1;
		}
		// con esto el autor está marcando los casos extremos (cuando muere el soldado de más a la derecha o el de más a la izquierda), para poder identificarlos en el ciclo for de más abajo 
		right[s] = -1;
		left[1] = -1;

		int l, r;
		for (int i = 0; i < b; i++) {
			scanf("%d %d", &l, &r);

			// el nuevo "buddie" izquierdo del soldado inmediatamente a la derecha del último soldado a eliminar (R) será ahora el que esté a la izquierda del primero a eliminar
			left[right[r]] = left[l];
			// imprimimos el primer soldado del nuevo par generado...
			if (left[l] != -1)
				printf("%d", left[l]);
			// ... o imprimimos '*' si se eliminó el soldado de más a la izquierda de los restantes
			else
				printf("*");

			// el nuevo "buddie" derecho del soldado inmediatamente a la izquierda del primer soldado a eliminar (L) será ahora el que esté a la derecha del último a eliminar
			right[left[l]] = right[r];
			// imprimimos el segundo soldado del nuevo par generado...
			if (right[r] != -1)
				printf(" %d\n", right[r]);
			// ... o imprimimos '*' si se eliminó el soldado de más a la derecha de los restantes
			else
				printf(" *\n");
		}
		printf("-\n");
	}

	return 0;
}
