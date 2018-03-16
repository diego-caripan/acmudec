#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(1){
		vector <int> num;
		int aux;
		for(int i=0; i<n; i++){
			cin >> aux;
			num.push_back(aux);
		}
		vector <int> perm(6);
		for(int i=0; i<n; i++){
			perm[0] = num[i];
			for(int j=i+1; j<n; j++){
				perm[1] = num[j];
				for(int k=j+1; k<n; k++){
					perm[2] = num[k];
					for(int l=k+1; l<n; l++){
						perm[3] = num[l];
						for(int h=l+1; h<n; h++){
							perm[4] = num[h];
							for(int g=h+1; g<n; g++){
								perm[5] = num[g];
								cout << perm[0] << " ";
								for(int p=1; p<perm.size()-1; p++){
									cout << perm[p] << " ";
								}
								cout << perm[perm.size()-1] << '\n';
							}
						}
					}
				}
			}
		}
		cin >> n;
		if(n == 0) return 0;
		cout << '\n';
	}
}