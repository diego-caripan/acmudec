#include <iostream>
using namespace std;

int main(){
	int n,k,l,m; // n:carne, k:sarten
	cin >> n;
	cin >> k;
	if(n<1 || n>1000 || k<1 || k>1000)
		cin >> n,k;
	l = n*2;
	m = l%k;
	if(k >= n)
		cout << "2";
	else if (m == 0)
		cout << l/k;
	else if (m != 0)
		cout << l/k + 1;
}