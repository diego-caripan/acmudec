#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){

	int n,m;
	int max = 0;
	vector <int> sum;

	while(cin >> n >> m){
		max = 0;
		sum.clear();
		sum.resize(n+m+1);
		for(int i = 0; i <= n+m; i++) sum[i]= 0;


		for(int i = 1; i <= n;i++){
			for(int j = 1 ; j <=m; j++){
				sum[i+j] += 1;
				if(sum[i+j]> max) max = i+j;
			}

		}

		
		for(int j = 0; j < n+m; j++) {

			if(sum[j] == max) printf("%d\n",j);
		}
		printf("\n");

	}




	return 0;
}