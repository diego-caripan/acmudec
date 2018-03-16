#include <bits/stdc++.h>  
using namespace std;  

// No terminado

#define rep(i,a,n) for(int i=a;i<(int)n;++i)
typedef long long ll;

int main(){
	
	int n1, n2;
	vector <int> maxi, aux;

	scanf("%d", &n1);
	aux.push_back(n1);

	while(scanf("%d", &n2) != EOF){
		if (n1 < n2) aux.push_back(n2);
		else{
			if (maxi.size() <= aux.size()) maxi = aux;
			aux.clear();
			aux.push_back(swap);
		}
		n2(n1,n2);
	}

	if (maxi.size() <= aux.size()) maxi = aux;
	printf("%d\n-\n",maxi.size() );
	for (int i: maxi) printf("%d\n", i );

}