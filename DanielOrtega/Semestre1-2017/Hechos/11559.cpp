#include <iostream>
#include <climits>

using namespace std;


int main() {

	int n, b, h, w;
	int hoteles[19][14];
	int precio_total, menor, precio_h;
	bool flag;


	while (scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {

		flag = false;
		menor = INT_MAX;

		for (int i = 0; i < h; i++) {

			cin >> precio_h;

			precio_total = n * precio_h;

			for (int j = 0; j < w; j++) {

				cin >>  hoteles[i][j];

				if (b < precio_total)
					continue;

				if (n <= hoteles[i][j] && menor > precio_total) {
					flag = true;
					menor = precio_total;
				}

				flag = false;
			}

		}

		if (menor != INT_MAX) {
			cout << menor << "\n";
		}
		else {
			cout << "stay home\n";
		}
	}
}
