/*************************************************************************************************************************
 * UVa 10801 - Lift Hopping
 * http://uva.onlinejudge.org/external/108/10801.html
 *
 * Classification: Shortest Path Algorithm
 *
 * Author: Javier González N.
 *
 * Date: 17-08-2014
 *
 * Description:
 * The problem can be represented by a shortest path in a graph. Each node is a floor where a elevator can stop and
 * the edge between two nodes is the time needed to go from one floor to another. There are at most five elevators,
 * so for example floor 10 can be represented by 10 for elevator 0, 110 for elevator 1, 210 for elevator 2 and so on.
 * In order to consider the switch elevator time, you can have an edge between 10 and 110 with time 60 seconds (This
 * means you can switch elevator at floor 10)
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <queue>
#include <map>
using namespace std;

#define MAX_ELEVATORS 6
#define MAX_FLOORS 504
#define INF 999999

int elevatorTime[MAX_ELEVATORS];

int main()
{
    int n, ki;

    while(cin >> n >> ki)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> elevatorTime[i];
        }

        vector< vector< pair<int, int> > > G(MAX_FLOORS); //Graph
        vector<int> canBeReached[MAX_ELEVATORS]; //List of floors that can be reached by elevator i
        map<int, bool> isInArr[MAX_ELEVATORS]; //This is to know if two elevators stop at the same floor.

        string line;
        getline(cin, line);
        //First connects each node from one particular elevator.
        for(int i = 0; i < n; i++)
        {
            getline(cin, line);
            string token;
            istringstream iss(line);

            int prev = -1;

            while(getline(iss, token, ' '))
            {
                int currFloor = atoi(token.c_str());

                if(prev != -1)
                {
                    int distance = (currFloor - prev) * elevatorTime[i];
                    int n1 = prev + 100 * i;
                    int n2 = currFloor + 100 * i;

                    G[n1].push_back(make_pair(n2, distance));
                    G[n2].push_back(make_pair(n1, distance));


                }

                canBeReached[i].push_back(currFloor);
                isInArr[i][currFloor] = true;

                prev = currFloor;
            }
        }

        //If two elevators stop at the same floor, then an edge is needed.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < canBeReached[i].size(); j++)
            {
                int floor = canBeReached[i][j];
                for(int k = i + 1; k < n; k++)
                {
                    if(isInArr[k][floor])
                    {
                        int n1 = floor + 100 * i;
                        int n2 = floor + 100 * k;

                        G[n1].push_back(make_pair(n2, 60));
                        G[n2].push_back(make_pair(n1, 60));
                    }
                }
            }
        }

        //We can start at elevator 0, 1, 2, 3, or 5 at floor 0. If we choose one or another
        //we will get different resutls. So we need a dummy node to allow our shortst path algorithm
        //to find the correct answer.
        for(int i = 0; i < n; i++)
        {
           G[501].push_back(make_pair(100 * i, 0));
        }

        //Dikstra, extracted from Competitive Programming 3, Felix Halim, Page 148
        vector<unsigned int> dist(MAX_FLOORS, INF);
        dist[501] = 0;
        priority_queue< pair<unsigned int, int>, vector< pair<unsigned int, int> >, greater< pair<int, int> > > pq;
        pq.push(make_pair(0, 501));
        while(!pq.empty())
        {
            pair<unsigned int, int> front = pq.top();
            pq.pop();
            int d = front.first;
            int u = front.second;
            if(d > dist[u])
                continue;

            for(int j = 0; j < (int)G[u].size(); j++)
            {
                pair<int, int> v = G[u][j];
                if(dist[u] + v.second < dist[v.first])
                {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(make_pair(dist[v.first], v.first));
                }
            }
        }

        //Reach floor k means reach floor k, k + 100, k + 200, k + 300, k + 400 and k + 500 (one for
        //each elevator. We need to find the lowest of them.
        unsigned int result = INF;
        for(int i = 0; i < n; i++)
        {
            result = min(result, dist[ki + 100 * i]);
        }

        if(result != INF)
            cout << result << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
