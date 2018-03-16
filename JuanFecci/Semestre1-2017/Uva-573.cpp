#include <bits/stdc++.h>
using namespace std;

int main(){

	float H, U, D, F, sum, desc, day, aux;
	while (cin >> H >> U >> D >> F) {
		if (H==0) break;
		sum = 0;
		desc = U*F/100;
		day = 1;
		while(1){
			sum += U;
			aux = U;
			U -= desc;
			if (U < 0) U=0;
			if (sum > H){
				cout << "success on day " << day << "\n";
				break;
			}
			sum -= D;
			if (sum < 0){
				cout << "failure on day " << day << "\n";
				break;
			}
			day++;
		}
	}

	return 0;
}