#include <bits/stdc++.h>
using namespace std;

int main(){
	int k,n;
	cin >> k >> n;
	int a[n+1];
	a[n]=0;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++){
		a[i]-= k;
		if(a[i]>0) a[i+1]+=a[i];
 	}
	cout << a[n]<< endl; 
	return 0;
}