#include <bits/stdc++.h>
using namespace std;

int main(){
	int T,A[3];
	cin >> T;
	for(int i=1; i<=T; i++){
		for(int j=0; j<3 ;j++) cin >> A[j];
		sort(A,A+3);
		cout << "Case " << i << ": " << A[1] << endl;;
	}
	return 0;
}