/*************************************************************************************************************************
 * UVa 10959 - The Party, Part I
 * http://uva.onlinejudge.org/external/109/10959.html
 *
 * Classification: BFS (Breadth First Search)
 *
 * Author: Javier González N.
 *
 * Date: 12-08-2014
 *
 * Description:
 * Each pair of people dancing is a pair of connected nodes in a bidirectional graph. Then the giovanni number is the shortest path from
 * node 0 to node T (where T es the person with id T). Each edge has a value of 1 and hence we can use bfs to determine shortest path from
 * node 0 to each other node.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1005

vector< vector<int> > G(MAX);
int gioNum[MAX];
bool bVisited[MAX];

int main()
{
    int T;
    bool blank = false;

    cin >> T;

    while(T--)
    {
        int P, D;
        cin >> P >> D;

        for(int i = 0; i < P; i++)
        {
            G[i].clear();
            gioNum[i] = -1;
            bVisited[i] = false;
        }

        while(D--)
        {
            int p1, p2;
            cin >> p1 >> p2;

            G[p1].push_back(p2);
            G[p2].push_back(p1);
        }

        gioNum[0] = 0;
        queue<int> Q;
        Q.push(0);

        while(!Q.empty())
        {
            int curr = Q.front();
            Q.pop();

            if(bVisited[curr])
                continue;

            bVisited[curr] = true;

            for(int i = 0; i < G[curr].size(); i++)
            {
                int u = G[curr][i];
                if(gioNum[u] == -1)
                {
                    gioNum[u] = gioNum[curr] + 1;
                    Q.push(u);
                }
            }
        }

        if(blank)
        {
            cout << endl;
        }

        blank = true;

        for(int i = 1; i < P; i++)
        {
            cout << gioNum[i] << endl;
        }
    }

    return 0;
}
