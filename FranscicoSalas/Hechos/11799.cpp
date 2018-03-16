#include <iostream>

using namespace std;

int main(){ 
	int cases, serial, max, aux;
	cin >> cases;
	for(int i = 0; i < cases; i++){
		cin >> serial;
		max = 0;
		for(int j = 0; j < serial; j++){
			cin >> aux;
			if(aux > max){
				max = aux;
			}
		}
		cout << "Case " << i+1 << ": " << max << endl;
	}
	return 0;
}
