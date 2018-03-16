#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// intervalo
typedef struct {
    double l, r;
} DD;

// funcion de comparacion. Compara intervalos segun su extremo izquierdo
int cmp(const void *i, const void *j) {
    DD *a, *b;
    a = (DD *)i, b = (DD *)j;
    return a->l < b->l ? -1 : 1;
}

int main() {
    int n, l, w;
    double x, r;
    int i, j;
    while(scanf("%d %d %d", &n, &l, &w) == 3) {
        int m = 0;
        DD D[10000];
        for(i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &r);
            // calcula los extremos del intervalo que cubre el circulo dado
            if(r > w/2.0) {
                double ll = x - sqrt(r*r - w*w/4.0);
                double rr = x + sqrt(r*r - w*w/4.0);
                D[m].l = ll, D[m].r = rr;
                m++;
            }
        }
        // ordena los intervalos segun cual comienza antes
        qsort(D, m, sizeof(DD), cmp);
        int ch, flag = 0;
        double right = 0;
        for(i = 0, j = 0; i < m; i++) {
            double tmp = right;
            ch = -1;
            // mientras el rango cubierto sea menor que el rango total
            // y no quede un espacio entre el intervalo actual y el anterior
            while(j < m && D[j].l <= right) {
            	// si encontramos un intervalo que cubra mas, actualizamos el intervalo a elegir
                if(D[j].r > tmp) {
                    tmp = D[j].r;
                    ch = j;
                }
                j++;
            }
            // si cubrimos todo el rango, imprimimos la resulesta y salimos del loop
            // seteamos un flag para que no imprima el -1 abajo
            if(tmp >= l) {
                printf("%d\n", i+1);
                flag = 1;
                break;
            }
            // si no, no hay solucion. rompemos el loop
            if(ch == -1)
                break;
            right = tmp;
        }
        if(!flag)    puts("-1");
    }
    return 0;
}