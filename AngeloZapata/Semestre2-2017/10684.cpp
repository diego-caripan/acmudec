#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		int sum = 0, summax = 0, sum2 = 0, aux;
		if(n == 0) return 0;
		for(int i=0; i<n; i++){
			cin >> aux;			
			if(sum < 0){
				if(sum > summax) summax = sum;
				sum = 0;
			}
			sum += aux;
			if(sum > summax) summax = sum;
		}
		(summax>0)? cout << "The maximum winning streak is " << summax << ".\n":
					cout << "Losing streak.\n";

	}
}