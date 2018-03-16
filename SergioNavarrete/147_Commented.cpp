#include<cstdio>
#define N 30002

// Es un problema similar al COIN CHANGE (674) en el que se usa DP para resolver
// Lo curioso del problema es que la cantidad puede ser flotante
// La forma de solucionar el calculo del decimal y la porcion fracional por separado es:
// Dado que $1 son 100 centavos entonces $4.70 son 470 centavos,asi podemos simplemente calcular con los centavos de cuantas maneras las monedas pueden usarse
// Cada vez que podamos dividir la cantidad con una moneda en especifico, incrementaremos el contador. Esto se calcula para todas las monedas.

using namespace std;

static long long c[N];
static const unsigned coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main(){
    unsigned i, j;
    float n;

    c[0] = 1;
    for(i = 0; i < 11; ++i){
        for(j = coins[i]; j < N; ++j)
            c[j] += c[j - coins[i]];
    }

    while(scanf("%f", &n) == 1 && n){
        // Rounding error fix
        unsigned coin = (unsigned)((n + 0.001) * 100);

        // 6 width justified including the input amount and 17 width afterwards including count
        printf("%6.2f%17lld\n", n, c[coin]);
    }
    return 0;
}
