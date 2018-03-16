//codigo comentado
// Fuente: https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%20514%20-%20Rails/src/UVa%20514%20-%20Rails.cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, target[1000];
	int i;

	while (true) {
		cin >> n;
		if (n == 0)
			break;

		while (true) {
			cin >> target[0];
			if (target[0] == 0){	// si el valor leido es 0 se imprime un salto de linea como lo indica el ejercicio
				cout << endl;
				break;
			}
			for (i = 1; i < n; i++) {	//se llena el arreglo con los valores desde la posicion uno ya que la posicion cero ya tiene su valor
				cin >> target[i];
			}

			int currCoach = 1, targetIndex = 0;
			stack<int> station;
			while(currCoach<=n){
				station.push(currCoach); //mientras que el numero de coachs sea menor o igual al numero de de bloques, se ingresa al stack el numero

				while(!station.empty() && station.top() == target[targetIndex]){ //si el stack no esta vacio y el ultimo elemento ingresado
					station.pop();												// es igual al elemento del arreglo en la posicion del targetIndex	
					targetIndex++;											//el target index aumenta y si este es mayor o igual a n, el ciclo se termina
					if(targetIndex>=n) break;								//en otro caso se aumenta el numero de coach hasta que el numero ingresado
				}															// es igual al que esta en el arreglo en la posicion targetIndex

				currCoach++;
			}

			if(station.empty()) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}
