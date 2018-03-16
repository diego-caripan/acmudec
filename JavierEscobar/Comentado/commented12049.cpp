#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
int main() {
    scanf("%*d");
    int n, m, x;
    while(scanf("%d %d", &n, &m) == 2) {
        map<int, int> r;
        /*agregar la primera lista de numeros al map
          cada valor tiene asociada una cantidad
          de instancias en la lista*/
        while(n--)
            scanf("%d", &x), r[x]++;
        /*quitar las cantidades de la segunda 
          si un numero tiene una cantidad absoluta 0,
          significa que ambas listas son iguales en 
          cuanto a ese numero*/
        while(m--)
            scanf("%d", &x), r[x]--;
        x = 0;
        /*mostrar en pantalla la cantidad absoluta de
          diferencias: esta es la cantidad de elementos 
          a remover*/
        for(map<int,int>::iterator it = r.begin();
            it != r.end(); it++)
            x += abs(it->second);
        printf("%d\n", x);
    }
    return 0;
}