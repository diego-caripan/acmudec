#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,B,H,W,p,a,cont=0,i,j;
	long int T = 500001;
	while(cin >> N >> B >> H >> W){
		for(i=0 ; i<H ; i++){
			cin >> p;
			for(j=0 ; j<W ; j++){
				cin >> a;
			if(p*N<=B && p*N<T && a>=N)
				T = p*N;
			}
			if(cont==W && p*N<=B && p*N<T)
				T = p*N;
			cont = 0;
		}
		if(T < 500001 && T < B)
			cout << T << endl;
		else
			cout << "stay home" << endl;
		T=500001;
	}
	return 0;
}