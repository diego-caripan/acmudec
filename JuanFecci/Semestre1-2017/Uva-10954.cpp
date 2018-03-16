#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

//Accepted

int main(){

	priority_queue <int> pq;
	int n, aux, aux1, aux2, cost;

	scanf("%d", &n);
	while(n!=0){
		REP(i,0,n){
			scanf("%d", &aux);
			pq.push(aux*-1);
		}

		cost = 0;
		while (pq.size() > 1){	
			aux1 = pq.top();
			pq.pop();
			aux2 = pq.top();
			pq.pop();
			aux = aux2+aux1;
			cost+=aux*-1;
			pq.push(aux);
		}

		pq.pop();
		printf("%d\n", cost);
		scanf("%d", &n);
	}

}