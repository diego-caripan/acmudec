#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	if(k>n) cout << 2 << endl;
	else if((2*n)%k>=1){
		cout<< (2*n/k) +1 << endl;
	}else{
		cout<< 2*n/k << endl;
	}
	return 0;
}