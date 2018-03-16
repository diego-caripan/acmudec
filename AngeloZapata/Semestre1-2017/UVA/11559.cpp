#include <bits/stdc++.h>
#define D(a) cout << a << "\n"
#define REP(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main(){
	int N,B,H,W,p,a;
	while(cin >> N >> B >> H >> W){
		bool existe = false;
		int result=INT_MAX;
		REP(i,0,H){
			int cont=0;
			cin >> p;
			REP(j,0,W){
				int aux;
				cin >> aux;
				if(aux>=N) cont++;
			}
			if(cont>=1 && N*p<=B){
				if(result > N*p) result = N*p;
				existe = true;
			}
		}
		if(existe) D(result);
		else D("stay home");
	}
	return 0;

}