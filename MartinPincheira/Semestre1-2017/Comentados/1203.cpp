#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
#include <iostream>
#include <functional>

using namespace std;

int main() {

	char s[20];
	int qnum, p, n;
	//Se utiliza una cola de prioridad de pares para resolver este problema ya que se necesita asociar cada ID-number
	//y Period, con el mismo Period yaque este va aumentado de acuerdo al valor inicial. 
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

	//Se hace la lectura de datos y almacenamiento en la cola de prioridad, la cual es de acuerdo al elemento mas pequeño
	while (scanf("%s", s), strcmp("#", s)) {

		scanf("%d %d", &qnum, &p);
		pq.push(pair<int, pair<int, int> >(p, pair<int, int>(qnum, p)));
	}

	scanf("%d", &n);

	//Por cada iteracion se entrega el Id-number y se aumenta Period en su valor inicial, y se vuelve a insertar en la 
	//cola de prioridad. Para ello se utiliza un par de elementos auxiliar.
	while (n--) {
		
		pair<int, pair<int, int> > pr = pq.top();
		pq.pop();
		printf("%d\n", pr.second.first);
		pr.first += pr.second.second;
		pq.push(pr);
	}

	return 0;
}
