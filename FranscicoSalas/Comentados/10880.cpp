// Este problema es básicamente ver todos los múltiplos posibles de la diferencia entre C y R
// tales que sean mayores que R
// Se dificulta cuando se usan números muy grandes por lo que comentaré esta solución

#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main() {
	int cases; cin >> cases;
	for (int C, R, c = 1; cases--; ++c) {
		cin >> C >> R;
// Se define un set para guardar los resultados
		set<int> res;
		int diff = C - R;
		cout << "Case #" << c << ":";
		if (diff == 0) {
			cout << " 0" << endl;
			continue;
		}
// Se itera hasta la diferencia, con la condición de que 'i*i <= diff', así se itera muchas menos veces
		for (int i = 1; i * i <= diff; ++i)
// Si diff%i==0 significa que i es múltiplo de la diferencia, por lo que se inserta al set
// también se inserta diff/i, es decir, el caso cuando , recordar que se itera por i*i
			if (diff % i == 0) {
				res.insert(diff / i);
				res.insert(i);
			}
// Se imprimen los resultados con la condición de que el valor sea > R
		for (set<int>::iterator it = res.begin(); it != res.end(); it++)
			if (*it > R) cout << " " << *it;
		cout << endl;
	}
	return 0;
}