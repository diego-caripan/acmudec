#include <cstdio>
#include <iostream>

using namespace std;


unsigned long long int digitos(unsigned long long int n){
	unsigned long long int x = 0;
	if(n<=9){
		return n;
	}
	while(n != 0){
		x += n%10;
		n = n/10; 
	}
	if(x > 9) digitos(x);

	else return x;
}

int main(){
	unsigned long long int N;
	while(1){
		cin >> N;
		if (N == 0) break;
		cout << digitos(N) << endl;
	}
	return 0;
}
