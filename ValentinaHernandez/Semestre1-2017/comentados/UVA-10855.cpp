/*codigo comentado
https://github.com/morris821028/UVa/blob/master/volume108/10855%20-%20Rotated%20square.cpp#L1 */
#include <stdio.h>
#include <string.h>

char big[500][500], small[500][500];
/*Se crean las matrices para el cuadrado grande
y el mas pequeño que se va a rotar, con la capacidad
maxima*/

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
/*Compara el cuadrado pequeño con el cuadrado grante
va moviendo el cuadrado pequeño en base al grande y los
compara*/

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
/*Rota los cuadrados pequeños, cada vez que se llama se
rota en 90°*/

int main() {
    int n, m, i;
    while(scanf("%d %d", &n, &m) == 2) {
        if(n == 0 && m == 0)
            break;
        /* Lee n(N) y m(n), sin son 0 termina*/
        for(i = 0; i < n; i++)
            scanf("%s", big[i]);
        //se lee el cuadrado grande
        for(i = 0; i < m; i++)
            scanf("%s", small[i]);
        //se lee el cuadrado pequeño a buscar
        for(i = 0; i < 4; i++) {
            /*Aqui, se llama a find antes de rotar el cuadrado, para hacer
            la comparación la primera vez sin rotacion y despues cada vez que 
            se debe rotar, haciendo las 4 comparaciones*/
            if(i)
                putchar(' ');
            printf("%d", find(n, m));
            rotate(m);
        }
        puts("");
    }
    return 0;
}