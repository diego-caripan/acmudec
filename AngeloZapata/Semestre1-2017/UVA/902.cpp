#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		map <string,int> cont;
		int max=0;
		string pass,aux;
		cin >> pass;
		for(int i=0; i<pass.size(); i++){
			aux = pass.substr(i,n);
			cont[aux]++;
		}
		for (map<string,int>::iterator it=cont.begin(); it!=cont.end(); ++it){
			if(it->second > max){
				aux = it->first;
				max = it->second;
			}
		}
		cout << aux << endl;
	}
	return 0;
}