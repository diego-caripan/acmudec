/*************************************************************************************************************************
 * UVa 926
http://uva.onlinejudge.org/external/9/p926.pdf
 *
 * Classification: BFS, DP
 *
 * Author: Diego Seco
 *
 * Date: 15-09-2014
 *
 * Description: DP, graph traversal
*/

#include <iostream>
#include <utility>
#include <string.h>

using namespace std;

unsigned long long int roadsCount[31][31];
bool roadsDisc[31][31][31][31];

unsigned long long int dp(int sx, int sy, int ex, int ey) {
	if(sx == ex && sy == ey) {
		roadsCount[ex][ey]=1;
		return 1;
	}
	if(roadsCount[sx][sy]!=-1)
		return roadsCount[sx][sy];
	roadsCount[sx][sy]=0;
	if(sx<ex && !roadsDisc[sx][sy][sx+1][sy])
		roadsCount[sx][sy]+=dp(sx+1,sy,ex,ey);
	if(sy<ey && !roadsDisc[sx][sy][sx][sy+1])
		roadsCount[sx][sy]+=dp(sx,sy+1,ex,ey);
	return roadsCount[sx][sy];
}

int main() {
	int testCases;
	cin >> testCases;
	while(testCases--) {
		int n,numdisc;		
		cin >> n;
		memset(roadsCount, -1, sizeof roadsCount);
		memset(roadsDisc, false, sizeof roadsDisc);
		pair<int,int> start,end;
		cin >> start.first >> start.second >> end.first >> end.second >> numdisc;
		for(int i=0; i<numdisc; i++) {
			int discX,discY;
			char dir;
			cin >> discX >> discY >> dir;
			if(dir=='N') {
				roadsDisc[discX][discY][discX][discY+1]=true;
			} else if(dir=='S') {
				roadsDisc[discX][discY-1][discX][discY]=true;
			} else if(dir=='W') {
				roadsDisc[discX-1][discY][discX][discY]=true;
			} else if(dir=='E') {
				roadsDisc[discX][discY][discX+1][discY]=true;
			}
		}

		cout << dp(start.first, start.second, end.first, end.second) << endl;
	}
	return 0;
}
