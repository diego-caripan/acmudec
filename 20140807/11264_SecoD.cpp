/*************************************************************************************************************************
 * UVa 11264 - Coin Collector
 * http://uva.onlinejudge.org/external/112/11264.html
 *
 * Classification: Greedy
 *
 * Author: Diego Seco
 *
 * Date: 09-08-2014
 *
 * Description: We can always use the first and last coin
 * Greedy selection from the beginning of the array
*/

#include <iostream>

using namespace std;

int main()
{
	int numTests;
	cin >> numTests;
	while(numTests--) {
		int numCoins;
		cin >> numCoins;
		int coins[numCoins];
		for(int i=0; i<numCoins; i++) {
			cin >> coins[i];
		}
		int sum = 1;
		int result = 2; //we always use the first and last one
		for(int i=1; i<numCoins-1; i++) {
			if(sum+coins[i]<coins[i+1]) {
				sum+=coins[i];
				result++;
			}
		}
		cout << result << endl;
	}
	return 0;
}