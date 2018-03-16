#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

	int n1, n2, n3;
	int total = 0;

	cin >> n1;
	int a[n1]; 

	for(int i = 0;i < n1; ++i){
		cin >> a[i];
	}

	cin >> n2;
	int b[n2];

	for(int i = 0;i < n2; ++i){
		cin >> b[i];
	}

	cin >> n3;
	int c[n3];

	for(int i = 0;i < n3; ++i){
		cin >> c[i];
	}

	for(int i = 0,j = 0,k = 0;i < n1;++i){

		while(n3 > k){ 
			if(a[i] > c[k]){
				++k;
			}
			else
				break;
		}

		while(n2 > j){
			if(a[i] > b[j]){
				++j;
			}
			else
				break;
		}

		if(c[k] == a[i] && a[i] == b[j]){
			++total;
		}
	}

	cout << total << endl;

	return 0;
}
