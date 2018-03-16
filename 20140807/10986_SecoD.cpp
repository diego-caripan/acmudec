/*************************************************************************************************************************
 * UVa 10986 - Sending email
 * http://uva.onlinejudge.org/external/109/10986.html
 *
 * Classification: Dijkstra
 *
 * Author: Diego Seco
 *
 * Date: 10-08-2014
 *
 * Description: Classical Dijkstra
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 20000

vector<pair<int,int> > servers[MAX];
bool visited[MAX];

int dijkstra(int orig, int targ) {
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
	q.push(make_pair(0,orig));
	int cSol = 0;
	while(!q.empty()) {
		pair<int,int> cPair = q.top(); q.pop();
		int cost = cPair.first;
		if(cSol > 0 && cSol <= cost)
			return cSol;
		int cServer = cPair.second;
		if(!visited[cServer]) {
			visited[cServer] = true;
			for(int i=0; i<servers[cServer].size(); i++) {
				pair<int,int> reach = servers[cServer][i];
				if(reach.second == targ && (!cSol || cost+reach.first<cSol))
					cSol = cost+reach.first;
				q.push(make_pair(cost+reach.first, reach.second));
			}
		}
	}
	return -1;
}

int main()
{
	int numTests;
	cin >> numTests;
	for(int nTest = 0; nTest < numTests; nTest++) {
		cout << "Case #" << nTest+1 << ": ";
		int n,m,s,t;
		cin >> n >> m >> s >> t;
		if(!m) {
			cout << "unreachable" << endl;
			continue;
		}

		for(int i=0; i < n; i++) {
			servers[i].clear();
			visited[i]=false;
		}
		while(m--) {
			int x,y,w;
			cin >> x >> y >> w;
			servers[x].push_back(make_pair(w,y));
			servers[y].push_back(make_pair(w,x));
		}
		int resDij = dijkstra(s,t);
		if(resDij == -1)
			cout << "unreachable" << endl;
		else
			cout << resDij << endl;

	}
	return 0;
}