#include <cstdio>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

int main() {

	int n;
	
	while (scanf("%d", &n), n) {
		//Se utiliza una cola de prioridad para ir almacenando los valores, dejando los valores de menor a mayor.
		priority_queue<int, vector<int>, greater<int> > q;
		
		//Lectura y almacenamiento de los valores en la cola de prioridad q.
		while (n--) {

			int x;
			scanf("%d", &x);
			q.push(x);
	
		}

		int total = 0, cost = 0;

		//Mientras la cola de prioridad tenga un tamaño mayor a 1 se sumara el valor que se encuentra al principio
		//con el segundo. Ambos numeros salen de la cola de prioridad y la suma se almacena en la variable cost, para
		//luego ser insertado nuevamente en la cola de prioridad y ser sumado con el siguiente valor.
		while (q.size() > 1) {

			total = q.top();
			q.pop();
			total += q.top();
			q.pop();
			cost += total;
			q.push(total);
		}

		printf("%d\n", cost);
	}

	return 0;
}
