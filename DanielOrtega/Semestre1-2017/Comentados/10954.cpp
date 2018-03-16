#include <cstdio>
#include <queue> 
#include <functional> // std::greater
using namespace std;

/*
este problema consiste en que dado una sucesion de numeros, se busque la forma de sumar de obtener el menor costo.
es decir, dado x,y,z
x+y=w
w+z=t,
donde w+t, tenga el menor valor posible


para este ejercicio se ocupa una priority_queue, con la funcion greater, que retorna si el primer elemento es mayor al segundo (>)


para este ejercicio 
se leen los numeros y son puestos en la cola de prioridad, para luego realizar operaciones y obtener asi el menor costo

la complejidad del ejercicio consistia en encontrar la estructura de datos correcta para resolverlo.
*/

int main() {
	int n;

	while (scanf("%d", &n), n) {
		priority_queue<int, vector<int>, greater<int> > q;

		while (n--) {
			int x;
			scanf("%d", &x);
			q.push(x);
		}

		int total = 0, cost = 0;
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