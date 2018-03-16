#include <iostream>
#include <cmath>
using namespace std;


int main() {



	int n, k;
	int numero, total = 0, resto;
	int restita;
	cin >> k >> n;


	for (int j = 0; j < n; j++) {
		cin >> numero;


		if (k > numero) {



			if (total > 0) {

				restita = k - numero;
				if ((total - restita) < 0)
					total = 0;
				else {
					total = total - restita;
				}
			}



		} else {

			total += numero - k;

		}

	}

	cout << total << "\n";

	return 0;
}

