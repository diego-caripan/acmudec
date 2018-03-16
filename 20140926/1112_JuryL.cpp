/*************************************************************************************************************************
 * Uva 1112 - Mice and Maze
 *
 * Classification: 
 *
 * Author: Jury
 *
 * Date: 26-09-2014
 *
 * Descripcion:
 * 
**/
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

#define INF 200000000

int main()
{
    bool first = false;
    int C;
    scanf("%d", &C);
    while( C-- )
    {
      if( first ) printf("\n");
      first = true;

      int N,E,T,M;
      scanf("%d %d %d %d", &N, &E, &T, &M);
      std::vector< std::vector< int > > V( N+5, std::vector<int>( N+5, INF ) );
      for( int i = 0; i < M; ++i )
      {
          int a,b,c;
          scanf("%d %d %d", &a, &b, &c);
          V[a][b] = c;
      }
      for( int i = 1; i < V.size(); ++i ) V[i][i] = 0;

      for( int k = 1; k < V.size(); ++k )
          for( int i = 1; i < V.size(); ++i )
              for( int j = 1; j < V.size(); ++j )
                  if( V[i][j] > V[i][k] + V[k][j] )
                      V[i][j] = V[i][k] + V[k][j];

/*
      for( int i = 1; i < V.size(); ++i ){
          for( int j = 1; j < V.size(); ++j )
              printf("%d ", V[i][j]);
          printf("\n");
      }*/

      int count = 0;
      for( int i = 1; i < V.size(); ++i )
          if( V[i][E] <= T )
              count++;
      printf("%d\n", count);
    }
    return 0;
}
