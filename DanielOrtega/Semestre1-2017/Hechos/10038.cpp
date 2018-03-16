#include <cstdlib>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int casos, aux, resta;
	vector<int> nros;
	bool flag;

	while (scanf("%d", &casos) != EOF) {
		int numeros[3002] = {0};
		nros.clear();
		flag = true;

		for (int i = 0 ; i < casos; i++) {
			cin >> aux;
			nros.push_back(aux);
		}

		for (int i = 1; i < casos; i++) {

			resta = abs(nros.at(i) - nros.at(i - 1));
			if (resta <= 3000) numeros[resta]++;
		}

		for (int i = 1; i < casos; i++) {
			
			if (numeros[i] == 0) {
				flag = false;
				break;
			}

		}

		if (flag)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}

	return 0;
}