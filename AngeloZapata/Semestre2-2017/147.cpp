#include <bits/stdc++.h>
using namespace std;

int main(){
	int monedas[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
	vector <long long> dp(30001);
	dp[0] = 1;
	for(int i=0;i<11;i++){
		for(int j=monedas[i];j<30001;j++){
			dp[j] += dp[j - monedas[i]];
		}
	}
	double n;
	while(cin >> n){
		if(n == 0) return 0;
		printf("%6.2lf%17lld\n",n,dp[(int)(n*100 + 0.5)]);
	}

}
