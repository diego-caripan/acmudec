//codigo comentado
//Fuente: https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%2011385%20-%20Da%20Vinci%20Code/src/UVa%2011385%20-%20Da%20Vinci%20Code.cpp
#include <cstdio>
#include <cmath>
#include <map>
#include <cctype>
#include <cstring>
using namespace std;

map<int, int> fibIdx, revFibIdx;

int fib(int n) { //funcion que se encarga de calcular el valor en la secuencia de fibonacci
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (fibIdx.count(n) != 0) // Para ahorrarse el tiempo, si ya fue calculado el valor y se guardo en el mapa, se envia el valor del mapa
        return fibIdx[n];

    int ans = fib(n - 1) + fib(n - 2);
    fibIdx[n] = ans;
    revFibIdx[ans] = n;
    return ans;
}

void init() {   //funcion que llena los mapas hasta el valor 46
    fibIdx[1] = 1;
    fibIdx[2] = 2;
    revFibIdx[1] = 1;
    revFibIdx[2] = 2;
    fib(46);
}

int main() {
    int tc, n, i;
    char s[10001], ans[10001], c;
    int key[100];

    init(); // se llenan los mapas

    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        int max = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &key[i]); // se guarda el valor en el arreglo y se va buscando el valor mayor
            if (key[i] > max)
                max = key[i];
        }

        i = 0;
        scanf("%c", &c);
        while (true) {
            scanf("%c", &c);
            if (c == '\n')
                break;
            if (isupper(c)) // ve si la letra es mayuscula
                s[i++] = c; //se va guardando en un arreglo de char
        }

        for (i = 0; i < revFibIdx[max]; i++) { //va llenando todo el arreglo respuesta con espacios
            ans[i] = ' ';
        }
        for (i = 0; i < n; i++) { // va llenando en la parte que corresponde con la letras
            ans[revFibIdx[key[i]] - 1] = s[i];
        }
        ans[revFibIdx[max]] = '\0';

        printf("%s\n", ans);
    }

    return 0;
}