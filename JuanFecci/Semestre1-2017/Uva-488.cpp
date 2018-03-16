#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a; i< b; i++)
#define D(a) cout << a << "\n"

int main(){

	int N, n1, n2;

	cin >> N;
	REP(i,0,N){
		cin.ignore();
		cin >> n1 >> n2;
		if (i!=0) printf("\n");
		REP(j,0,n2){
			REP(k,1,n1+1){
				REP(y,0,k) printf("%d", k);
				printf("\n");
			}
			for (int k=n1-1; k > 0; k--){
				REP(y,0,k) printf("%d", k);
				printf("\n");
			}
			if (j!=n2-1)printf("\n");
		}
	}

}