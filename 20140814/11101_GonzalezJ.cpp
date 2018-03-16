/*************************************************************************************************************************
 * UVa 11101 - Mall Mania
 * http://uva.onlinejudge.org/external/111/11101.html
 *
 * Classification: Breadth First Search (BFS)
 *
 * Author: Javier González N.
 *
 * Date: 15-08-2014
 *
 * Description:
 * The problem is to find the minimum manhattan distance between two pair of points. One pair from the perimeter of the first mall and
 * the other one from the second mall. Trying each pair of points and store de minimum value give you TLE (Time Limit Exceed), to
 * get accepted you need to do a better algorithm, a BFS in a 2D array (x-y coords) will work. Mark the perimeter points of the second mall
 * in the array and the first mall points add them to the BFS queue. Then run BFS, the first time you visit a point from the second mall you will
 * the answer.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 2005

char city[MAX][MAX];
bool bVisited[MAX][MAX];

int main()
{
    int n;

    while(cin >> n && n != 0)
    {
        queue< pair< pair<int, int>, int> > Q;

        for(int i = 0; i < MAX; i++)
        {
            for(int j = 0; j < MAX; j++)
            {
                city[i][j] = '-';
                bVisited[i][j] = false;
            }
        }


        while(n--)
        {
            int x, y;
            cin >> x >> y;
            city[x][y] = '1'; //Not necessary
            Q.push(make_pair(make_pair(x, y), 0));
        }

        cin >> n;
        while(n--)
        {
            int x, y;
            cin >> x >> y;
            city[x][y] = '2';
        }

        while(!Q.empty())
        {
            pair< pair<int, int>, int> curr = Q.front();
            Q.pop();

            if(city[curr.first.first][curr.first.second] == '2')
            {
                cout << curr.second << endl;
                break;
            }

            int cX = curr.first.first;
            int cY = curr.first.second;

            //Necessary, TLE otherwise.
            if(bVisited[cX][cY])
            {
                continue;
            }

            bVisited[cX][cY] = true;

            if(cX > 0) Q.push(make_pair(make_pair(cX - 1, cY), curr.second + 1));
            if(cX < MAX - 1) Q.push(make_pair(make_pair(cX + 1, cY), curr.second + 1));
            if(cY > 0) Q.push(make_pair(make_pair(cX, cY - 1), curr.second + 1));
            if(cY < MAX - 1) Q.push(make_pair(make_pair(cX, cY + 1), curr.second + 1));
        }
    }

    return 0;
}
