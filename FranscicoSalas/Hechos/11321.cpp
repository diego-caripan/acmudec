#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct number{
	int num;
	int mod;
	number(int n, int m){
		num = n;
		mod = m;
	}
};

bool compare(number* a, number* b){
	if(a->mod < b->mod)
		return true;
	if(a->mod == b->mod){
		if(abs(a->num)%2 == 1 && abs(b->num)%2 == 0)
			return true;
		if(abs(a->num)%2 == 0 && abs(b->num)%2 == 1)
			return false;
		if(abs(a->num)%2 == 1 && abs(b->num)%2 == 1)
			return a->num > b->num;
		if(abs(a->num)%2 == 0 && abs(b->num)%2 == 0)
			return a->num < b->num;
	}
	else 
		return false;
}

int main(){
	int N, M, nu;
	while(1){
		N = 0, M = 0, nu = 0;
		cin >> N >> M;
		if(N == 0 & M == 0)
			break;
		//cout << "N : " << N << " M : " << M << endl;
		number* n[N];
		int aux = 0;
		for(int i = 0; i < N; i++){
			cin >> aux;
			n[i] = new number(aux, aux%M);
		}
		sort(n,n+N,compare);
		cout << N << " " << M << endl;
		for(int i = 0; i < N; i++){
			//cout << n[i]->mod << " " << n[i]->num << endl;
			cout << n[i]->num << endl;
		}
	}
	
	cout << "0 0" << endl;
}

			
