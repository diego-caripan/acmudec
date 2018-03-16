/*************************************************************************************************************************
 * UVa 11264 - Coin Collector
 * http://uva.onlinejudge.org/external/112/11264.html
 *
 * Classification: Greedy
 *
 * Author: Jury
 *
 * Date: 11-08-2014
 *
 * Description:
 * Idea General, Si se tienen las monedas 1, 3, 6, 8, 15, 20. y el arreglo
 * A = [1,4,12,32] donde, A[i] representa el valor minimo que se puede
 * formar con i monedas.
 * al escribir todas las posibles combinaciones de valores que se pueden
 * formar con estas monedas (sin repetir ninguna moneda y siguiendo la 
 * regla del enunciado), se nota que A[i] = A[i-1] + X, donde X es el valor
 * de alguna moneda.
 *
 * Luego, se parte del valor A[0] = 1, y se itera para ir encontrando
 * los valores que siguen.
 */

#include <vector>
#include <stdio.h>

int main()
{
  int T, n;
  scanf("%d",&T);
  while( T-- )
  {
    scanf("%d", &n );
    std::vector<int> coins;

    for( int i = 0; i < n; ++i)
    {
        int a;
        scanf("%d", &a);
        coins.push_back( a );
    }
    
    int suma = 1;
    int monedas = 1;

    for( int i = 1; i < n-1; ++i )
    {
      int tmp = suma + coins[i];
      if( tmp < coins[i+1] )
      {
          suma = tmp;
          monedas++;
      }
    }
    monedas++; //la ultima moneda siempre cuenta
    printf("%d\n", monedas);
  
  }

  return 0;
}
