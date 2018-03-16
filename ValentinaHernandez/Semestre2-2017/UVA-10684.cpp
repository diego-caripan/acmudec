#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		if(N == 0) break;
		int valor,sum = 0, i = 0, j = 0, t = 0, max = 0;
		for(int h=0 ; h<N ; h++){
			cin >> valor;
			sum += valor;
			if(sum >= max){
				j = h;
				max = sum;
			}
			else if(sum < 0){
				i = h;
				sum = 0;
			}
		}
		if(max > 0)
			cout << "The maximum winning streak is " << max << ".\n";
		else
			cout << "Losing streak.\n";
	}
	return 0;
}