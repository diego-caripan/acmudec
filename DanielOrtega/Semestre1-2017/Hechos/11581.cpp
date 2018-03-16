#include <iostream>
#include <stdio.h>
#include <istream>


using namespace std;

int matriz[4][4];

void funcionf() {
	int prima[4][4];

	prima[0][0] = (matriz[0][1] + matriz[1][0]) % 2;
	prima[0][1] = (matriz[0][0] + matriz[1][1] + matriz[0][2]) % 2;
	prima[0][2] = (matriz[0][1] + matriz[1][2]) % 2;
	prima[1][0] = (matriz[0][0] + matriz[1][1] + matriz[2][0]) % 2;
	prima[1][1] = (matriz[0][1] + matriz[1][0] + matriz[1][2] + matriz[2][1]) % 2;
	prima[1][2] = (matriz[1][1] + matriz[0][2] + matriz[2][2]) % 2;
	prima[2][0] = (matriz[2][1] + matriz[1][0]) % 2;
	prima[2][1] = (matriz[2][0] + matriz[1][1] + matriz[2][2]) % 2;
	prima[2][2] = (matriz[2][1] + matriz[1][2]) % 2;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matriz[i][j] = prima[i][j];
		}
	}
}



void limpiar() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matriz[i][j] = 0;
		}
	}
}


int main() {


	int casos;

	char str[4];

	scanf("%d", &casos);
	getchar();

	while (casos--) {
		int aux = 0;

		limpiar();
		for (int i = 0; i < 3; i++) {
			getchar();
			fgets (str, 4,  stdin);
			
			for (int j = 0; j < 3; j++) {
				matriz[i][j] = str[j] - '0';
			}
		}
		getchar();
	
		int intentos = -1;
		int bandera =0;
		while (!bandera) {

			bandera = 1;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (matriz[i][j] > 0) {

						bandera = 0;
						break;
					}
				}
			}

			if (bandera) break;
			funcionf();
			
			
			intentos++;

		}
		cout  << intentos << endl;


	}

	return 0;
}