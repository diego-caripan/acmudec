#include<cstdio>

// Este es un problema de el maximo sub array. Para encontrar el maximo en un arreglo de 1D. Puede ser resuelto con Kadane Algorithm en tiempo O(n)
// Otro problema es el input
// Si la suma de elementos es 0 deberiamos setear la "sum" a 0. De otra man era, la suma seria negativa y no obtendriamos la respuesta correcta
// dado que podriamos obtener una suma mas grande descartando ese subset negativo de sumas.

using namespace std;

static int subset[10002];

int main(){
    static unsigned n, i;
    static int sum, max;

    while(scanf("%u", &n) && n){

        sum = max = i = 0;

        for(; i < n; ++i){
            scanf("%d", &subset[i]);
            sum += subset[i];

            if(sum < 0)
                sum = 0;

            if(sum > max)
                max = sum;
        }

        if(max > 0)
            printf("The maximum winning streak is %d.\n", max);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
