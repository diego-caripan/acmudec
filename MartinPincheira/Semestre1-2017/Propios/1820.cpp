#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	int n, k;
	int tiempo = 0;

	cin >> n;
	cin >> k;

	if(n <= k){ 
		
		tiempo = 2;
		cout << tiempo << endl;
	}
	
	else{
	
		tiempo = (2*n - 1 + k)/k;
		cout << tiempo << endl;
	}
	
	return 0;	
}
