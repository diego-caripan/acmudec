#include <bits/stdc++.h>  
using namespace std;  

#define rep(i,a,n) for(int i=a;i<(int)n;++i)
typedef long long ll;

int kadane(vector <int> vec){
	int suma=0, maxsuma = 0;
	bool verif = false;
	rep(i,0,vec.size()){
		suma += vec[i];
		if (suma < 0){
			suma = 0;
		}
		else if (suma > maxsuma){
			maxsuma = suma;
			verif = true;
		}
	}

	if (verif) return maxsuma;
	maxsuma = vec[0];
	rep(i,1,vec.size()) if (maxsuma < vec[i]) maxsuma = vec[i];
	return maxsuma;
}

int main(){
	int N, aux;
	scanf("%d", &N);
	vector <vector <int> > matrix (N, vector <int> (0));

	rep(i,0,N) rep(j,0,N){
		scanf("%d", &aux);
		matrix[i].push_back(aux);
	}

	int maxsuma, suma;
	bool verif = true;
	vector <int> temporal;

	rep(l,0,N){
		temporal = vector <int> (N,0);
		rep(r,l,N){
			rep(i,0,N) temporal[i] += matrix[i][r];
			suma = kadane(temporal);
			if (suma > maxsuma || verif) {
				maxsuma = suma;
				verif = false;
			}
		}
		
	}

	printf("%d\n", maxsuma );
}