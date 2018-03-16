#include <iostream>

using namespace std;

int main(){

	int cases, stores, mid, min, max, final, aux;

	cin >> cases;

	for(int i = 0; i < cases; i++){
		cin >> stores;
		min = 100; 
		max = 0;
		for(int j = 0; j < stores; j++){
			cin >> aux;
			if(aux <= min)
				min = aux;
			if(aux >= max)
				max = aux;
		}
		mid = (max - min)/2; // mejor lugar donde estacionar
		final = (max - mid)*2 + (mid - min)*2; //ida y vuelta
		cout << final << endl;
	}

}