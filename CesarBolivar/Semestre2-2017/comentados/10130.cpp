#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 1010
#define MAX_W 40

int i, T, G, ans, N, MW, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

// DP top down
int value(int id, int w)
{
    // casos base
	if (id == N || w == 0) {
		return 0;
	}
    // si el elemento actual existe, no hay que calcularlo de nuevo. Lo retornamos
	if (memo[id][w] != -1) {
		return memo[id][w];
	}
    // si el peso del objeto es mayor que el que podemos llevar, retornamos actualizamos la tabla y retornamos el valor correspondiente
	if (W[id] > w) {
		return memo[id][w] = value(id + 1, w);
	}
    // si no, llamamos recursivamente y retornamos el maximo
	return memo[id][w] =
		max(value(id + 1, w), V[id] + value(id + 1, w - W[id]));
}

int main()
{
	scanf("%d", &T);
    // por cada test case...
	while (T--) {
        // inicializa la tabla con -1
		memset(memo, -1, sizeof memo);

		scanf("%d", &N);
        // por cada objeto se lee su valor y su peso
		for (i = 0; i < N; i++) {
			scanf("%d %d", &V[i], &W[i]);
		}

		ans = 0;
		scanf("%d", &G);
        // por cada miembro de la familia...
		while (G--) {
            // se lee el maximo peso que puede cargar
			scanf("%d", &MW);
            // se llama a la funcion recursiva y se acumula el resultado en esta variable
			ans += value(0, MW);
		}

		printf("%d\n", ans);
	}

	return 0;
}
