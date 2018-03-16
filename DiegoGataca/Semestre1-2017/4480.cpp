	#include <bits/stdc++.h>
	typedef long long ll;
	using namespace std;

	int main(){
		int n,aux,auxy,iter,jter,cont;	
		while(1){
			scanf("%d",&n);
			if(n == 0)break;	
			vector <int> x(n),y(n);
			vector <ll> pit(n);
			for(int i = 0; i < n; i++){
				scanf("%d %d",&aux,&auxy);
				x[i] = aux;
				y[i] = auxy;
			}
			int solucion = 0;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++)pit[j]=(ll)( (ll)(x[i]-x[j])*(ll)(x[i] - x[j])+(ll)(y[i]-y[j])*(ll)(y[i]-y[j]));
				sort(pit.begin(),pit.end());
				iter = 0;
				while(iter < n){
					jter = iter;
					while(jter < n && pit[iter]== pit[jter])jter++;
					cont = jter - iter;
					solucion+=(cont*(cont-1))>>1;
					iter = jter;
				}
			}
			printf("%d\n",solucion);
		}
		return 0;
	}
