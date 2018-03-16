#include <bits/stdc++.h>  
using namespace std;  

#define rep(i,n) ;for(int i=0; i<(int)n; ++i)
typedef long long ll;

int main(){
	bool verif = false;
	int n;

	scanf("%d", &n);
	while (n!=0){

		if (verif) printf("\n");

		vector <int> vec(n);

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &vec[i]);
		}
		sort(vec.begin(), vec.end())

		rep(n1,n) {rep(n2,n){
			if(n1 == n2) continue;
			else rep(n3,n){
				if (n3==n1 || n3 == n2) continue;
				else rep(n4,n){
					if (n4 == n3 || n4 == n2 || n4 == n1) continue;
					else rep(n5,n){
						if (n5 == n4 || n5 == n3 || n5 == n2 || n5 == n1) continue;
						else rep(n6, n){
							if (n6 == n5 || n6 == n4 || n6 == n3 || n6 == n2 || n6 == n1) continue;
							else if(n1<n2 && n2<n3 && n3 < n4 && n4 < n5 && n5 < n6) printf("%d %d %d %d %d %d\n", vec[n1], vec[n2], vec[n3], vec[n4], vec[n5], vec[n6]);
						}
					}
				}
			}
		}}
			

		verif = true;
		scanf("%d", &n);
		
	}
}