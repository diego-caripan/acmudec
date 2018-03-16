#include <bits/stdc++.h>
using namespace std;

int despedazar(int n) {
	if(n < 10)	return n;
	int sum = 0;
	while(n) {
		sum += n%10;
		n /= 10;
	}
	return despedazar(sum);
}

int main(){
	int n;
	//cin>>n;
	while(scanf("%d", &n) == 1 && n){
		cout<<despedazar(n)<<endl;
	}

}