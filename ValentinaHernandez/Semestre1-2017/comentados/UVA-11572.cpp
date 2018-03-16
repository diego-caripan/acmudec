/*COMENTADO
https://github.com/ksaveljev/UVa-online-judge/blob/master/11572.cpp
*/
#include <iostream>
#include <map>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
    int cases, n;
    int snowflake;
    int *snowflakes = new int[1000001];
    int first, current, result, counter;

    cin >> cases;

    while (cases--) {
        first = current = result = counter = 0;
        map<int,bool> taken;

        cin >> n;

        while (n--) {

            cin >> snowflake;
            snowflakes[current++] = snowflake;

            if (taken.find(snowflake) != taken.end()) {
                if (counter > result) result = counter;
                /*
                *Se busca el numero ingresado y se busca en el map, si ya esta ingresado,
                y el counter (contador de snowflakes unicos) es mayor al resultado actual,
                entonces el resultado es el snowflakes, que seria el resultado de la mayor
                cantidad hasta el momento
                */
                while (true) {
                    if (snowflakes[first] == snowflake) break;
                    taken.erase(snowflakes[first]);
                    counter--;
                    first++;
                    /*
                    si ya se tomo el snowflake 2 veces, se borra
                    */
                }
                
                first++;
            } else {
                counter++;
                taken[snowflake] = true;
            }
        }

        if (counter > result) result = counter;
        /*En el caso en donde no se paso por el if anterior en donde se cambiaba
        el estado del resultado si es que el counter era mas grande, se cambia aqui*/
        cout << result << endl;
    }

    delete snowflakes;

    return 0;
}