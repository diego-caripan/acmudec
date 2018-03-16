#include <bits/stdc++.h>

using namespace std;

int main(){
	int N,K,M;
	int total;
	int algo;
	char lol;
	map <char,int> hols;
	string parrafo;
	cin>>N;
	while(N>0){
		total=0;
		cin>>K;
		for(int i=0;i<K;i++){
			cin>>lol>>algo;
			hols[lol]=algo;
		}
		cin>>M;
		for(int i=0;i<=M;i++){
			getline(cin,parrafo);
			for(int j=0;j<parrafo.size();j++){
				total += hols[parrafo[j]];
			}
			parrafo.clear();
		}
		N--;
		hols.clear();
		printf("%d.%.2d$\n",total/100,total%100);

	}
	return 0;
}