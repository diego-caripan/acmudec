// @BEGIN_OF_SOURCE_CODE
//como que sobran varias cosas xD
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
//el problema trata de dado unos numeros que representa fibo y dado un string
// se debe crear un nuevo texto con las posiciones de los numeros se inserta el caracter del string
int nums [100];
LL fibs [100];
map <LL, int> map_fibo;
 //metodo que genera todas las posiones de los numeros de fibonacci
void generateFibo ()
{
    fibs [0] = 1;
    fibs [1] = 2;
 
    map_fibo [1] = 0;
    map_fibo [2] = 1;
 
    for ( int i = 2; fibs [i - 1] < (LL) 2147483648; i++ ) {
        fibs [i] = fibs [i - 1] + fibs [i - 2];
        map_fibo [fibs [i]] = i;
    }
}
 
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    //gerena los numeros de 
    generateFibo ();
    //la cantidad de casos a analizar
    while ( testCase-- ) {
        int n;
        scanf ("%d", &n);
 
        int maxi = INT_MIN;
        for ( int i = 0; i < n; i++ ) {
            scanf ("%d", &nums [i]);
            if ( maxi < nums [i] ) maxi = nums [i];
        }
        getchar ();
        //lee el string
        char str [100 + 10];
        gets (str);
 
        char output [100 + 10];
        //reserva bloques de memoria con memset y lo llena con espacios
        memset (output, ' ', sizeof (output));
 
        output [map_fibo [maxi] + 1] = 0;
 
        int str_len = 0;
        //ve si la la letra es una mayuscula o minuscula
        for ( int i = 0; i < n; i++ ) {
            while ( !isupper (str [str_len]) ) str_len++;
            //reemplaza los espacios en blanco por la letra que existe en la posicion fibo
            output [map_fibo [nums [i]]] = str [str_len];
            str_len++;
        }
 
        printf ("%s\n", output);
    }
 
    return 0;
}
 
// @END_OF_SOURCE_CODE