/*****************************************************************************************************************
 * Uva 10986 - Sending email
 * http://uva.onlinejudge.org/external/109/10986.html
 *
 * Classification: Distancia mas corta (Dijkstra)
 *
 * Author: Jury
 *
 * Date: 11-08-2014
 *
 * Descripcion:
 *  Calcular distancia mas corta entre el nodo S y T.
 *  Implementacion de dijkstra de Felix Halim, llegar y usar.
 */

#include <utility>
#include <vector>
#include <queue>
#include <stdio.h>

typedef std::pair<int,int> ii;
typedef std::vector<int> vi;
typedef std::vector<ii> vii;
#define TRvii(c, it ) for( vii::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000

int main()
{
    int N;
    scanf("%d", &N);
    for( int C = 1; C <= N; ++C )
    {
        int n,m,S,T;
        scanf("%d %d %d %d", &n, &m, &S, &T);
        std::vector<vii> AdjList(n);
 //       printf("a: %d %d %d %d\n", n,m,S,T);
        for( int i = 0; i < m; ++i )
        {
            int a,b,w;
            scanf("%d %d %d", &a, &b, &w);
   //         printf("%d %d %d\n", a,b,w);
            AdjList[a].push_back( ii(b,w) );
            AdjList[b].push_back( ii(a,w) );
        }

        std::vector<int> dist(n, INF); 
        dist[S] = 0;
        std::priority_queue<ii, std::vector<ii>, std::greater<ii> > pq; 
        pq.push(ii(0, S));

        while (!pq.empty())
        {
            ii top = pq.top(); pq.pop();
            int d = top.first, u = top.second;
            if (d == dist[u])
                TRvii (AdjList[u], it)
                {
                    int v = it->first, weight_u_v = it->second;
                    if (dist[u] + weight_u_v < dist[v]) 
                    {
                        dist[v] = dist[u] + weight_u_v;
                        pq.push(ii(dist[v], v));
                    }
                }
        }
        if( dist[T] == INF )
            printf("Case #%d: unreachable\n", C);
        else
            printf("Case #%d: %d\n", C, dist[T]);
    }
}
