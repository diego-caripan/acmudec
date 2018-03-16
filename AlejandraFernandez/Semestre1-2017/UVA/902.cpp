#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	char lol;
	map <string,int> hols;
	string parrafo,aux;
	while(cin>>N){
		int cont=0;
		cin>>parrafo;
		for(int i=0;i<parrafo.size();i++){
			aux = parrafo.substr(i,N);
			hols[aux]++;
		}
		for(map<string,int>::iterator it=hols.begin(); it!=hols.end();it++){
			if(it->second > cont){
				parrafo = it->first;
				cont = it ->second;
			}
		}
		hols.clear();
		cout<<parrafo<<endl;
	}
	return 0;
}