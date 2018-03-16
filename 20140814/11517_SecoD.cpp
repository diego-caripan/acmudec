/*************************************************************************************************************************
 * UVa 11517 - Exact Change
 http://uva.onlinejudge.org/external/115/11517.html
 *
 * Classification: DP
 *
 * Author: Diego Seco
 *
 * Date: 21-08-2014
 *
 * Description: Coin exchanged problem solved with dynamic programming
*/

#include <iostream>
#include <limits>

using namespace std;

#define MAX_PRICE 10001
int main()
{
	int numTests;
	int coins[100];
	int dp[MAX_PRICE];
	cin >> numTests;
	while(numTests--) {
		int price,numCoins;
		cin >> price >> numCoins;
		for(int i=0; i<numCoins; i++)
			cin >> coins[i];
		for(int i=1; i<MAX_PRICE; i++) {
			dp[i] = numeric_limits<int>::max(); 
		}

		dp[0] = 0;
		for(int i=0; i<numCoins; i++) {
			for(int j=MAX_PRICE-1; j>=0; j--)
				if(dp[j]<numeric_limits<int>::max() && j+coins[i]<MAX_PRICE && dp[j]+1<dp[j+coins[i]]) {
					dp[j+coins[i]] = dp[j]+1;
			}
		}
		for(int i=price; i<MAX_PRICE; i++) {
			if(dp[i]<numeric_limits<int>::max()) {
				cout << i << " " << dp[i] << endl;
				break;
			}
		}
	}
	return 0;
}