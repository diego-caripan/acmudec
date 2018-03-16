#include <stdio.h>
#include <string.h>

using namespace std;

char big[500][500], small[500][500];

/*Esta funcion se encarga de encontrar alguna ocurrencia de la matriz pequeña en la matriz de mayor tamaño.
Para ello se inicializa la variable ans que representa si es asi o no con los valores o y 1. Luego los dos primeros for creados son los que recorreran la matriz mas grande con una verificacion de que el indice mas el tamaño de la matriz pequeña no sobrepase el tamaño de la matriz grande por columnas y filas (i y j respectivamente).
A continuacion se realiza las comparaciones correspondientes entre la matriz pequeña y la mas grande. Si se encuentra una coincidencia en alguna posicion se aumenta el contador cnt, para luego verificar si el numero de coincidecias es igual al tamaño de la matriz pequeña, lo cual indica que en la matriz mas grande se encuentra una ocurrencia de la matriz pequeña.*/
int find(int n, int m) {

	int ans = 0, i, j, k, l;

		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {

				if(i+m <= n && j+m <= n) {

					int cnt = 0;
					for(k = 0; k < m; k++) {
						for(l = 0; l < m; l++) {
					
							if(big[i+k][j+l] == small[k][l])
								cnt++;
						}		
					}

					if(cnt == m*m)
						ans++;
				}
			}
		}
	
	return ans;
}

//La funcion rotate se encarga de rotar la segunda matriz, que es la matriz pequeña, la cual la rotara en 90°, 180° y 270°
//Para ello usa una matriz temporal en la cual se ira almacenando la matriz rotada, para luego ser copiada a la matriz
//original
void rotate(int n) {
	
	char tmp[n][n];
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			tmp[i][j] = small[n-j-1][i];
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			small[i][j] = tmp[i][j];
	}
}

int main() {

	int n, m, i;

	while(scanf("%d %d", &n, &m) == 2) {

		if(n == 0 && m == 0)
			break;
	
		//Se almacenan los caracteres de la matriz mas grande.
		for(i = 0; i < n; i++)
			scanf("%s", big[i]);
	
		//Se almacenan los caracteres de la matriz pequeña.
		for(i = 0; i < m; i++)
			scanf("%s", small[i]);
	
		//Aqui se imprimen los valores correspondientes 0 y 1 de cada rotacion si es que se encuentra alguna
		//ocurrencia.
		for(i = 0; i < 4; i++) {
			
			if(i)
				putchar(' ');
			
			printf("%d", find(n, m));
			rotate(m);
		}

		puts("");
	}

	return 0;
}
