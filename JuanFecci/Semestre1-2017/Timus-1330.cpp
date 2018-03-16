#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, q, i, j, k, aux;

	scanf("%d", &n);
	int sumas[n];
	sumas[0] = 0;
	for(k = 0; k<n; k++){
		scanf("%d", &aux);
		if (k == 0) sumas[1]=aux;
		else sumas[k+1]=aux+sumas[k];
	}	

	cin >> q;
	for(k=0; k<q; k++){
		scanf("%d %d", &i, &j);
		if (i==j && i != 1) cout << sumas[i] - sumas[i-1] << "\n";
		else if (i == 1)cout << sumas[j] << "\n";
		else cout << sumas[j] - sumas[i-1] << "\n"; 
	}
}