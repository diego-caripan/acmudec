#include <bits/stdc++.h>  
using namespace std;  

#define rep(i,a,n) for(int i=a;i<(int)n;++i)
typedef long long ll;

int main(){
	
	int n;
	scanf("%d", &n);

	ll maxi, suma;
	int larg, tem, ini, ed, aux;

	rep(i,0,n){
		scanf("%d", &larg);

		tem = 0; maxi = 0; suma = 0;
		ini = 0, ed = 0;
		rep(j,1,larg){
			scanf("%d", &aux);
			suma += aux;

			if (suma < 0){
				suma = 0;
				tem = j;
			}

			if (suma > maxi || (suma == maxi && ed - ini < j - tem) ){
				maxi = suma;
				ini = tem;
				ed = j;
			}
		}

		if (maxi == 0) printf("Route %d has no nice parts\n", i+1 );
		else printf("The nicest part of route %d is between stops %d and %d\n", i+1, ini+1, ed+1 );
	}	

}