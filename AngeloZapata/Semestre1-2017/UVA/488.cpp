#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, v1, v2;
	cin >> N;
	for(int i=0; i<N; i++){
		cin.ignore();
		cin >> v1 >> v2;
		if(i) printf("\n");
		for(int j=0; j<v2; j++){
			for(int k=1; k<=v1; k++){
				for(int x=0; x<k; x++) printf("%d", k);
				printf("\n");
			}
			for (int k=v1-1; k > 0; k--){
				for(int x=0; x<k; x++) printf("%d", k);
				printf("\n");
			}
			if (j != v2-1) printf("\n");
		}
	}

}