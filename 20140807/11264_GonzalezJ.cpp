/*************************************************************************************************************************
 * UVa 11264 - Coin Collector
 * http://uva.onlinejudge.org/external/112/11264.html
 *
 * Classification: Dynamic Programming
 *
 * Author: Javier González N.
 *
 * Date: 09-08-2014
 *
 * Description:
 * Dado un conjunto de monedas con distintos valores, nos piden la cantidad de monedas distintas que podemos
 * conseguir con una cierta cantidad de dinero dado el algoritmo descrito en el problema.
 *
 * Use el siguiente razonamiento para resolver el problema:
 * Por ejemplo, para el caso en que las monedas son 1 3 6 8 15 20
 *
 * 1. La primera moneda siempre vale 1, por lo que siempre puedo sacar una moneda si tengo dinero = 1
 *
 * 2. Si considero ahora la moneda que vale 3, entonces puedo sacar dos monedas con dinero = 4 (3 + 1)
 *
 * 3. Con la moneda que vale 6 puedo sacar 3 monedas, porque con dinero = 10 (6 + 4) saco la moneda que vale 6 y me
 *    queda dinero = 4. Ya se el resultado de dinero = 4 por el punto 2.
 *
 * 4. Moneda = 8. Podria sacar 18 (siguiendo el razonamiento anterior) porque 10 + 8 = 18. Pero, si uso el algoritmo
 *    del problema entonces el resultado es: 18 (eligo 8, me quedan 10), 10 (eligo 8, me quedan 2). El algoritmo elige dos veces
 *    8 y ese no es resultado que se esperaba (que eligiera las monedas 8, 6, 3 y 1) por lo que se puede deducir que no se puede elegir 10
 *    porque 10 > 8. Si elegimos la opcion 8 + 4 (punto 2) = 12 entonces si funciona. Elige la monedas 8, 3, 1.
 *
 * 5. Moneda = 15. Podemos elegir 12 (monedas 8, 3, 1 del punto 4) lo que nos daria dinero = 15 + 12 = 37. Pero nuevamente falla porque
 *    el algoritmo con dinero = 37 elige la moneda que vale 20. Por lo que se puede deducir que ademas de la restricción encontrada en el punto 4
 *    se debe considerar que dinero < siguiente moneda en la lista de monedas (La lista esta ordenada, asi que si dinero < siguiente moneda entonces
 *    es menor a todo el resto de estas). Luego, con la moneda 15, podemos sacar 3 monedas (15, 3, 1) con dinero = 19 (15 + 4)
 *
 * 6. Ya con la moneda = 20, usamos la información del punto 5 y podemos concluir que 20 + 19 = 39. Se pueden sacar 4 monedas (la 20 y las que se pueden
 *    sacar con dinero = 19, que ya sabemos que son las monedas 15, 3 y 1 por el punto 5)
 *
 * Al final, la información se puede representar en dos arreglos:
 * Dinero_necesario_moneda_i := [1, 4, 10, 12, 19, 39]
 * Monedas_distintas_i       := [1, 2,  3,  3,  3,  4]
 *
 * Cada indice es uno de los puntos descritos.
 */

#include <iostream>
#include <map>
using namespace std;

#define MAX 1005

int coins[MAX];
int accumulatedCoins[MAX];
long long accumulatedMoney[MAX];
int numCoins;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        cin >> numCoins;

        for(int i = 0; i < numCoins; i++)
        {
            cin >> coins[i];

            accumulatedCoins[i] = 0;
            accumulatedMoney[i] = 0;
        }

        accumulatedCoins[0] = 1;
        accumulatedMoney[0] = coins[0];

        //Algoritmo explicado en la descripción del problema.
        for(int i = 1; i < numCoins; i++)
        {
            int currentAccum = 0;
            long long currentMoney = 0;

            for(int j = 0; j < i; j++)
            {
                if(accumulatedMoney[j] < coins[i] && accumulatedCoins[j] > currentAccum && (i + 1 >= numCoins || (accumulatedMoney[j] + coins[i]) < coins[i + 1]))
                {
                    currentAccum = accumulatedCoins[j];
                    currentMoney = accumulatedMoney[j];
                }
            }

            if(currentAccum != 0)
            {
                accumulatedCoins[i] = currentAccum + 1;
                accumulatedMoney[i] = currentMoney + coins[i];
            }
            else
            {
                accumulatedCoins[i] = 1;
                accumulatedMoney[i] = coins[i];
            }
        }

        //El resultado esta en algún lugar del arreglo, asi que iteramos sobre el para encontrarlo.
        int maxDiffCoins = 0;
        for(int i = 0; i < numCoins; i++)
        {
            if(maxDiffCoins < accumulatedCoins[i])
            {
                maxDiffCoins = accumulatedCoins[i];
            }
        }

        cout << maxDiffCoins << endl;
    }

    return 0;
}
