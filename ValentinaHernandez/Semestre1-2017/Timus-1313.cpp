#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v;
	int n,i,x,j;
	cin >> n;
	while(n<0 || n>100)
		cin >> n;
	int a[n][n];
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++){
			cin >> x;
			a[i][j] = x;
		}
	}
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<=i ; j++){
			cout << a[i-j][j] << " ";
		}
	}
	for(i=1 ; i<n ; i++){
		for(j=n-1 ; j>=i ; j--){
			cout << a[j][n-1-j+i] << " ";
		}
	}
	cout << endl;
}