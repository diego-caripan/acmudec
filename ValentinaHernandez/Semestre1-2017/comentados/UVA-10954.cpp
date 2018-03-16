#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

/*Se guardan los numeros en la priority queue, despues se van sacando hasta que el size sea > 1,
porque se van sacando de a dos, si el size es 0, habria problemas al vaciar la queue.
Ahi se toma el primero, se suma con lo que habia en el el total, se borra el numero y se vuelve a 
sumar con el numero que sigue, a ese total "local", se le añade a la priority queue, para ir sumando
el costo final*/

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