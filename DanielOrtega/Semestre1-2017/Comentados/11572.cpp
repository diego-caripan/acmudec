#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;


/*
El problema consiste en dada una secuencia de enteros, encontrar la longitud de la subsecuencia mayor sin elementos repetidos

max_sf es donde se almacena el valor maximo, de los copos de nieves unicos que existen en un paquete,
por lo que este problema intenta generar las combinaciones posibles que son secuenciales, donde se guarda un copo de nieve de un solo tipo.
notar que el problema respeta el orden de entrada.


en el ejemplo dado en el caso el maximo numero es 3 y esta dado por los elementos 1 2 3


*/

int main() {

  int t;

  scanf("%d", &t);

  while (t--) {
    int n;

    scanf("%d", &n);

    int ci = 0, pi = 0, max_sf = 0;
    map<int, int> sf;


    // a medida que los numeros son leidos son ingresados a un par, donde se almacena el valor y un booleano
    // para luego ir siendo calculado,
    for ( ; ci < n; ci++) {
      int s;
      scanf("%d", &s);
      pair<map<int, int>::iterator, bool> result = sf.insert(make_pair(s, ci));

      // con s el valor asignado por ser unico
      // ci, el valor asociado al orden de entrada

        // result.second es una boleano, el cual inicialmente es falso, pero luego siempre es verdadero, 

      //-> es una mezcla entre el acceso y la desreferencia

      // result.first->second , result es una par, donde first es un map.
      // por lo que lo de arriba quiere decir, que accede al segundo elemento del map

      if (!result.second) {
      
        if (result.first->second >= pi) {
          max_sf = max(max_sf, ci - pi);
          pi = result.first->second + 1;
        }
        result.first->second = ci;
      }
    }

    max_sf = max(max_sf, ci - pi);
    printf("%d\n", max_sf);
  }


  return 0;
}

