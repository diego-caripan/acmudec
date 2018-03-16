#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int contador(map <vector<int>, int> ramos){
	int aux = 0, cont = 0;
	for(map<vector<int>, int>::iterator it=ramos.begin(); it!=ramos.end(); ++it){
		if (it->second > aux) aux=it->second;
	}
	for(map<vector<int>, int>::iterator it=ramos.begin(); it!=ramos.end(); ++it){
		if (it->second == aux) cont++;
	}
	return aux*cont;
}

int main(){
	int frosh = 1, max = 0;
	map <vector<int>, int > ramos;
	vector<int> asig;
	while(frosh){
		cin >> frosh;
		if(frosh == 0) return 0;
		for(int i=0; i<frosh; i++){
			for(int j=0; j<5; j++){
				int c;
				cin >> c;
				asig.push_back(c);
			}
			sort(asig.begin(),asig.end());
			if(ramos[asig]>=1){
				ramos[asig] = ramos[asig] + 1;
			}else{
			ramos[asig] = 1;
			}
			asig.clear();
		}
		max = contador(ramos);
		
		cout << max << endl;
		
		ramos.clear();
	}
}