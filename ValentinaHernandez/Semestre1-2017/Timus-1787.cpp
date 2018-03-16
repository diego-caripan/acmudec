#include <iostream>
using namespace std;

int main(){
	int i,n,k,r=0,x;
	cin >> k;
	cin >> n;
	while(n<1 || n>100)
		cin >> n;
	while(k<1 || k>100)
		cin >> k;
	for (i=0 ; i<n ; i++){
		cin >> x;
		x += r;
		if (k >= x)
			r = 0;
		else if (x > k)
			r = x - k;
		if (r < 0)
			r = r*(-1);
	}
	cout << r << endl;
}