// PROBLEMA 11995 COMENTADO

#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n, op, x;
	// Lee por entrada del teclado y guarda la variable en n que serán los siguientes valores a ingresar
	while (scanf("%d", &n) != EOF) {
	// Se define un queue, un stack y un priority_queue, y define los bools isS, isQ, isPQ todos verdaderos
	// Para las siguientes n líneas, leerá 2 valores: el primero define la acción de hacer push o pop a la estructura (1 push, 2 pop)
	// El segundo valor será el valor ingresado (si es hace push) o el valor esperado (si se hace pop)
	// A las 3 estructuras se les hace la misma acción
	// Si se ejecuta la acción 2, el programa compara el valor esperado con el valor actual de la estructura, es decir:
	// En el caso del stack, si el top del stack es distinto al valor esperado, se deja isS falso y en caso contrario se ejecuta el pop.
	// En el caso del queue, si el front del queue es distinto al valor esperado, se deja isQ falso y en caso contrario se ejecuta el pop.
	// En el caso del priority_queue, si el top del PQ es distinto al valor esperado se deja isPQ falso, caso contrario se hace el pop.
	// Después, dependiendo de los valores de isS, isQ e isPQ se imprime en pantalla:
	// Si isS es true, significa que es stack
	// Si isQ es true, significa que es stack
	// Si isPQ es true, significa que es priority_queue
	// Si mas de uno es true, imprime "not sure"
	// Si ninguno es true, imprime "impossible"
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		bool isS = true, isQ = true, isPQ = true;

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &op, &x);

			switch (op) {
			case 1:
				if (isS)
					s.push(x);
				if (isQ)
					q.push(x);
				if (isPQ)
					pq.push(x);
				break;
			case 2:
				if (isS) {
					if (s.empty() || s.top() != x)
						isS = false;
					else
						s.pop();
				}
				if (isQ) {
					if (q.empty() || q.front() != x)
						isQ = false;
					else
						q.pop();
				}
				if (isPQ) {
					if (pq.empty() || pq.top() != x)
						isPQ = false;
					else
						pq.pop();
				}
				break;
			}
		}

		if (isS == true && isQ == false && isPQ == false)
			cout << "stack" << endl;
		else if (isS == false && isQ == true && isPQ == false)
			cout << "queue" << endl;
		else if (isS == false && isQ == false && isPQ == true)
			cout << "priority queue" << endl;
		else if (isS == false && isQ == false && isPQ == false)
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;
	}
}