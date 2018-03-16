#include <bits/stdc++.h>  
using namespace std;  

#define rep(i,n) ;for(int i=0; i<(int)n; ++i)
typedef long long ll;

int main(){
	int N, M, S;
	vector <int> B(10001);

	scanf("%d", &N);
	while (N!=0){
		rep(i,N) scanf("%d", &B[i]);

		M=0;S=0;
		rep(i,N){
			S+=B[i];
			if(S<0) S=0;
			else if(S > M) M = S;
		}
		if(M>0) printf("The maximum winning streak is %d.\n",M);
		else printf("Losing streak.\n");
		scanf("%d", &N);
	}
}