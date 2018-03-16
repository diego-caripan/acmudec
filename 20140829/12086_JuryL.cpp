/*************************************************************************************************************************
 * Uva 12086 - Potentiometers
 * http://uva.onlinejudge.org/external/120/12086.pdf
 *
 * Classification: Estructuras de Datos
 *
 * Author: Jury
 *
 * Date: 29-08-2014
 *
 * Descripcion:
 * Basta con usar FenwickTree, este codigo utiliza la implementacion de felix
 * halim, ojo con la funcion adjust (y la linea 74)
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

#define LSOne(S) (S & (-S))

using namespace std;


typedef vector<int> vi;

class FenwickTree {
  public: 
  vi ft;
  FenwickTree(int n) { ft.assign( n+1, 0); }
    int rsq( int b) 
    {
        int sum = 0;
        for( ; b; b-= LSOne(b) ) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b)
    {
        return rsq(b) - ( a == 1 ? 0: rsq(a-1) ); 
    }
    void adjust( int k, int v ){ for(; k<(int) ft.size(); k += LSOne(k)) ft[k] += v;  }
};

int main() {
    int N, C=0;
    bool line = false;
    while( scanf("%d", &N) && N !=  0 )
    {
        if( line ) printf("\n"); line = true;
        FenwickTree ft(N);
        C++;

        for( int i = 1; i < N+1; ++i ){
            int a;
            scanf("%d", &a );
            ft.adjust(i,a);
        }
        std::cout << "Case " << C << ":" << std::endl;
        char c;

        while( scanf("%c", &c) && c != 'E' )
        {
            if( c == 'M' )
            {
                int a,b;
                scanf("%d %d", &a, &b);
                printf("%d\n", ft.rsq(a,b) );
            }
            else if( c == 'S' )
            {
                int a,b;
                scanf("%d %d", &a, &b);
                ft.adjust(a, b-ft.rsq(a,a) );
            }
        }
        scanf("ND");	
    }
        return 0;
}
