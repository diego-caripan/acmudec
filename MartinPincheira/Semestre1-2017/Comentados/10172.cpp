#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){

	int n, s, q, TC;
	cin >> TC;
	
	for(; TC > 0; TC--){

		/*Se utiliza un stack para los portadores ya que es ese el compartamiento que presentan segun el problema, y 			una cola de prioridad para las estaciones ya que asi se describe.*/
		stack<int> carrier;
		queue<int> stationQueue[100];
		cin >> n >> s >> q;

		for(int i = 0; i < n; i++){

			int nc;
			cin >> nc;
			for(int j = 0; j < nc; j++){

				int target;
				cin >> target;
				stationQueue[i].push(target - 1);
			}
		}
	
		int currPos = 0, time = 0; 

		while (true) {
		/*Esto se ecarga de descargar las cargas en las estaciones de destino hasta que el stack este vacio o que
		ocurra alguna falla, lo cual toma un tiemppo de 1 minuto.*/
			while (!carrier.empty()
					&& (carrier.top() == currPos
						|| stationQueue[currPos].size() < q)) {
				cout << "entro 1 while" << endl;
				cout << carrier.size() << endl;
				if (carrier.top() != currPos) {
		
					stationQueue[currPos].push(carrier.top()); //se deposita la carga en la estacion de
				}						   //destino
	
				carrier.pop();
				time++;
			}	
		/*Apila las cargas en el stack carrier hasta que este complete su capacidad, o hasta que la cola quede vacia, 			lo cual toma 1 minuto realizar esto.*/

			while ((carrier.size() < s) && !stationQueue[currPos].empty()) {
	
				carrier.push(stationQueue[currPos].front()); //push en el stack carrier
				stationQueue[currPos].pop();
				time++;
			}	

			bool clear = carrier.empty();

			for (int i = 0; i < n; i++) {
				clear &= stationQueue[i].empty();
			}
	
			if (clear)
				break;
			/*Se actualiza la posicion actual de las estaciones en la cola, lo cual moverlos toma un 
			tiempo de 2 minutos*/
			currPos = (currPos + 1) % n;
			time += 2;
		}

		cout << time << endl;
	}

	return 0;
}
