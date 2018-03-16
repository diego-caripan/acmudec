#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long

using namespace std;
//Lo que realiza este codigo es tomar los valores que se ingresan de posiciones de los amigos y almacenarlos en p y q 
//respectivamente, para luego ordenarlos por medio de la funcionde la stl sort, y asi obtener poder obtener los puntos
//que se encuentran en la mitad, que corresponde a la ubicacion mas conveniente. 
//Para ello lo separa en dos casos, donde el numero de amigos es par e impar, en donde para el primer caso se queda con
//la psoicion de (f-1)/2, y en el otro caso solo con f/2.

int main ()
{
    int testCase;
    scanf ("%d", &testCase);
 
    while ( testCase-- ) {
        int s, a, f;
        scanf ("%d %d %d", &s, &a, &f);
 
        int p [50000 + 5];
        int q [50000 + 5];
 
        for ( int i = 0; i < f; i++ )
            scanf ("%d %d", &p [i], &q [i]);
 
        sort (p, p + f);
        sort (q, q + f);
 	cout << f%2 << endl;
        if ( f % 2 ) printf ("(Street: %d, Avenue: %d)\n", p [f / 2], q [f / 2]);
        else printf ("(Street: %d, Avenue: %d)\n", p [(f - 1) / 2], q [(f - 1) / 2]);
    }
 
    return 0;
}
