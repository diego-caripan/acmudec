/*************************************************************************************************************************
 * UVa 10986 - Sending email
 * http://uva.onlinejudge.org/external/109/10986.html
 *
 * Classification: Shorthest path algorithm
 *
 * Author: Javier González N.
 *
 * Date: 11-08-2014
 *
 * Description:
 * Keep calm and do Dijkstra. After you read the description, you will notice that the problem
 * is a graph where you need to find the shortest path between two nodes.
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

#define MAX 20005
#define INF 99999999

int main()
{
    int T;
    scanf("%d", &T);

    vector< vector< pair<int, int> > > G(MAX);
    vector<int> dist(MAX);

    for(int c = 1; c <= T; c++)
    {
        int n, m, S, T;
        //cin >> n >> m >> S >> T;
        scanf("%d %d %d %d", &n, &m, &S, &T);

        for(int i = 0; i < n; i++)
        {
            G[i].clear();
            dist[i] = INF;
        }

        for(int j = 0; j < m; j++)
        {
            int a, b, l;
            //cin >> a >> b >> l;
            scanf("%d %d %d", &a, &b, &l);

            G[a].push_back(make_pair(b, l));
            G[b].push_back(make_pair(a, l));
        }

        dist[S] = 0;
        priority_queue< pair<int, int> > Q;
        Q.push(make_pair(0, S));

        while(!Q.empty())
        {
            pair<int, int> curr = Q.top();
            Q.pop();

            if(curr.second == T)
                break;

            if(-curr.first > dist[curr.second])
                continue;

            for(int i = 0; i < G[curr.second].size(); i++)
            {
                int u = G[curr.second][i].first;
                int vu = G[curr.second][i].second;

                if(dist[curr.second] + vu < dist[u])
                {
                    dist[u] = dist[curr.second] + vu;
                    Q.push(make_pair(-dist[u], u));
                }
            }
        }

        printf("Case #%d: ", c);//cout << "Case #" << c << ": ";

        if(dist[T] != INF)
            printf("%d\n", dist[T]);//cout << dist[T] << endl;
        else
            printf("unreachable\n");// << endl;
    }

    return 0;
}
