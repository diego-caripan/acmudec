#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
#include <map>

using namespace std;


int f, maxi;
int A[5];
string s;
stringstream ss; // sirve para almacenar un buffer, donde 

/*

*/

int main() {

    scanf("%d", &f);

    while (f) {

        maxi = 0;
        map <string, int> M;
        int aux = f;

        while (f--) {
            for (int i = 0; i < 5; i++) {
                scanf("%d", &A[i]);
            }

                // ordena el arreglo de de popularidas de menor a mayor
            sort(A, A + 5);

            ss.str(""); //si no se limpia se queda el buffer almacenado con el anterior

            for (int i = 0; i < 5; i++)
                ss << A[i]; //a es tipo int, c tipo string
            s = ss.str();

            /*
            En esta parte es importante notar que el valor de s se puede repetir varias veces, por lo que el valor de M[s], puede ser un
            numero mayor a 1,esto equivale a hacer un comparacion de igualdad, ya que cada vez que se tenga el mismo string, se ira en aumentando en 1
            la popularidad de cierta combinacion */ 
            M[s]++;

                // se procede a asignar el mayor a maxi, entre el maxi calculado anteriormente, o el M[s], actualizado en esta iteracion
            maxi = M[s] > maxi ? M[s] : maxi;
            
        }

        //si maxi es igual a 1, se imprime la respuesta
        if (maxi == 1)
            printf("%d\n", aux);
        //en otro caso, se procede a calcular cuantos valores, poseen la misma popularidad
        // es decir que el valor sea iguales
        else {
            int res = 0;

            // en esta parte se revisan cuando valores de numeros son iguales a maxi, se espera que el valor de res sea 1,
            //ya que solo debe existir una combinacion mas popular que tenga un valor mas alta que todas,
            // guardando en maxi, las veces que se obtiene ese valor de popularidad
            for (auto i = M.begin(); i != M.end(); i++) {
                if (i->second == maxi)
                    res++;
            }

            printf("%d\n", maxi * res);
        }

        scanf("%d", &f);

    }

    return 0;

}