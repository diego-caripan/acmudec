#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
/*
El problema consiste en saber cuantas galletas se comio cada invitado en la fista
sabiendo que la cantidad de galletas C y la cantidad que quedaro R
*/
int main() {
	//lee los casos
	int cases; cin >> cases;
	for (int C, R, c = 1; cases--; ++c) {
		//lee laas galletas y las que quedaron
		cin >> C >> R;
		//crea un set 
		set<int> res;
		//la diferencia, que es las que se comieron
		int diff = C - R;
		cout << "Case #" << c << ":";
		if (diff == 0) {
			cout << " 0" << endl;
			continue;
		}
		for (int i = 1; i * i <= diff; ++i)
			if (diff % i == 0) {
				//inserta en el set las posibles galletas comidas por cada uno
				//tomando 
				res.insert(diff / i);
				res.insert(i);
			}
		//recorre el set
		for (set<int>::iterator it = res.begin(); it != res.end(); it++)
			if (*it > R) cout << " " << *it;
		cout << endl;
	}
	return 0;
}