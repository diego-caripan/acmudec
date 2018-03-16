#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

int main() {

	int test, tam;
	long int k , t;
 	double valores[100], pago;
	unsigned char letras[100];
	string texto;

	scanf("%d", &test);

	while (test--) {
		pago = 0;
		scanf("%ld\n", &k);

		for (int j = 0; j < k; j++) {
			scanf("%c %lf\n", &letras[j], &valores[j]);
		}

		scanf("%ld\n", &t);
		for (int j = 0; j < t; j++) {
			getline(cin, texto);
			int tam  = texto.length();

			for (int i = 0; i < k; i++) {
				for (int q = 0; q < tam; q++) {
					if (texto[q] == letras[i]) {
						pago += valores[i];
					}
				}
			}
		}
		printf("%.2lf$\n", pago / 100);
	}
	return 0;
}