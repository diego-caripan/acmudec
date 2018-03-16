#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int main(){

	int n, aux, val1, val2, tam, resta;
	
	while(cin >> n && n!= 0){

		queue<int> Q;
		string S = "Jolly";
		vector<bool> V(n,false);			
		V[0] = true;
	
		int i = 0;

		while(n){
	
			cin >> aux;
			Q.push(aux);
			i++;
			n--;
		}
		
		tam = Q.size();
		for(int j = 1; j < tam; j++){

			val1 = Q.front();
			Q.pop();
			val2 = Q.front();
		
			resta = abs(val1 - val2);
			
			if(resta >= V.size()){
				S = "Not jolly";
				break;
			}
			
			V[resta] = true;
		}
	
		tam = V.size();
		for(int k = 0; k < tam; k++){
			
			if(V[k] == false){
				S = "Not jolly";
				break;
			}			
		}
		
		if(S == "Not jolly"){
			cout << S << endl;
		}
	
		else
			cout << S << endl;

	}
	
	return 0;
}
