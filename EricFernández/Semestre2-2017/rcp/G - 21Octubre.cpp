#include <bitset>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


typedef vector<int> vi;
typedef long long ll;


ll _sieve_size;
bitset <10000010> bs;
vi primes;
vi dist_prim;

int n_sieve;
int a ,b;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++) 
		if(bs[i]){
			for(ll j= i*i; j <= _sieve_size; j+= i)bs[j]=0;
			if(i >= a && i <= b)primes.push_back((int)i);
		}

}

void Maxprime(int a, int b){

	int max = 0;
	int aux;

	for(int i = 0; i < n_sieve-1 ; i++){

		aux = primes[i+1] - primes[i];

		if(max < aux ) max =  aux;

	}
	if(max == 0) printf("NULL\n");
	else printf("%d\n",max);
}

bool isPrime(ll N){
	if(N <= _sieve_size) return bs[N];
	for(int i = 0; i < (int)primes.size();i++)
		if(N % primes[i] == 0) return false;
	return true;
}


int main(){

	n_sieve = 0;

	while(1){

	cin >> a;
	cin >> b;

	if(a>b){
		int aux = a;
		a = b;
		b = aux;
	}
	
	if (a == 0 && b == 0) break;

	if(a == b){
		printf("NULL\n");
		continue;
	}


	sieve(b);
	n_sieve = primes.size();


	Maxprime(a,b);

	primes.clear();
	}

	return 0;
}