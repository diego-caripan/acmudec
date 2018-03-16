#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

//Time Limit

int dfsito(vector<int> gr, int s, vector<int> &dis){
	if (dis[s] > 0) return dis[s];
	dis[s] = 1;
	dis[s] = dfsito(gr,gr[s],dis) + 1;
	return dis[s];
}

int main(){
	int n, n2, aux1, aux2;
	vector <int>  gr, dis, vis;

	scanf("%d", &n);
	REP(i,0,n){
		scanf("%d", &n2);
		gr = vector<int> (n2);

		REP(j,0,n2){
			scanf("%d %d", &aux1, &aux2);
			gr[aux1-1] = aux2-1;
		}

		dis = vector <int>(n2);
		REP(j,0,n2) if (dis[j] ==0) dfsito(gr,j,dis);

		aux1=0;
		REP(j,1,n2){
			if (dis[aux1] < dis[j]) aux1 = j;
			else if (dis[aux1]==dis[j] && aux1 > j) aux1 = j;
		}
		printf("%d\n", aux1+1 );
	}
}