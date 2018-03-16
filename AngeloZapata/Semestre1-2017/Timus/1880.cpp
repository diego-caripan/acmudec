#include <bits/stdc++.h>
using namespace std;

int main(){
	map< string,int> alum;
	int n;
	string aux;
	for(int j=0; j<3; j++){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> aux;
			alum[aux]++;
		}
	}
	int cont=0;
	for (std::map<string,int>::iterator it=alum.begin(); it!=alum.end(); ++it){
    	if(it->second==3) cont++; 
	}
	cout<< cont << endl;
	return 0;
}