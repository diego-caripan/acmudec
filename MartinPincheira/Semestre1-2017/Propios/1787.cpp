#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	int k, n;
	
	cin >> k;
	cin >> n;
	
	int i, a,resto, sum = 0;	
	for(i=0;i<n;i++){
	
		cin >> a;
		sum = sum + a;
		resto = sum - k;
		sum = max(0,resto);
	}

	cout << sum << endl;

	return 0;	
}
